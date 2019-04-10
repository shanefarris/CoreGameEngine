// Proximity 
// Data structures for accelerating proximity/locality/neighborhood queries
#ifndef OPENSTEER_PROXIMITY_H
#define OPENSTEER_PROXIMITY_H

#include <algorithm>
#include <vector>
#include "Defines.h"
#include "LocalityQuery.h"   // XXX temp?

namespace Core 
{
namespace AI
{
    // ----------------------------------------------------------------------------
    // "tokens" are the objects manipulated by the spatial database
    template <class ContentType> class AbstractTokenForProximityDatabase
    {
    public:

        virtual ~AbstractTokenForProximityDatabase () {}

        // the client object calls this each time its position changes
        virtual void updateForNewPosition (const Vector3& position) = 0;

        // find all neighbors within the given sphere (as center and radius)
        virtual void findNeighbors (const Vector3& center,
                                    const float radius,
                                    std::vector<ContentType>& results) = 0;

#ifndef NO_LQ_BIN_STATS
        // only meaningful for LQProximityDatabase, provide dummy default
        virtual void getBinPopulationStats (int& min, int& max, float& average) { min = max=0; average = 0.0;}
#endif // NO_LQ_BIN_STATS
    };


    // ----------------------------------------------------------------------------
    // abstract type for all kinds of proximity databases
    template <class ContentType> class AbstractProximityDatabase
    {
    public:

        // type for the "tokens" manipulated by this spatial database
        typedef AbstractTokenForProximityDatabase<ContentType> tokenType;

        
        virtual ~AbstractProximityDatabase() { }
        
        // allocate a token to represent a given client object in this database
        virtual tokenType* allocateToken (ContentType parentObject) = 0;

        // insert
        // XXX maybe this should return an iterator?
        // XXX see http://www.sgi.com/tech/stl/set.html
        // virtual void insert (const ContentType& x) = 0;

        // XXX name?
        // returns the number of tokens in the proximity database
        virtual int getPopulation (void) = 0;
    };


    // ----------------------------------------------------------------------------
    // This is the "brute force" O(n^2) approach implemented in terms of the
    // AbstractProximityDatabase protocol so it can be compared directly to other
    // approaches.  (e.g. the Boids plugin allows switching at runtime.)
    template <class ContentType> class BruteForceProximityDatabase : public AbstractProximityDatabase<ContentType>
    {
    public:
        BruteForceProximityDatabase (void) { }
        virtual ~BruteForceProximityDatabase () { }

        // "token" to represent objects stored in the database
        class tokenType : public AbstractTokenForProximityDatabase<ContentType>
        {
        public:
            tokenType (ContentType parentObject, BruteForceProximityDatabase& pd)
            {
                // store pointer to our associated database and the object this
                // token represents, and store this token on the database's vector
                bfpd = &pd;
                object = parentObject;
                bfpd->group.push_back (this);
            }

            virtual ~tokenType ()
            {
                // remove this token from the database's vector
                bfpd->group.erase (std::find (bfpd->group.begin(), bfpd->group.end(), this));
            }

            // the client object calls this each time its position changes
            void updateForNewPosition (const Vector3& newPosition)
            {
                position = newPosition;
            }

            // find all neighbors within the given sphere (as center and radius)
            void findNeighbors (const Vector3& center,
                                const float radius,
                                std::vector<ContentType>& results)
            {
                // loop over all tokens
                const float r2 = radius * radius;
                for (tokenIterator i = bfpd->group.begin(); i != bfpd->group.end(); i++)
                {
                    const Vector3 offset = center - (**i).position;
                    const float d2 = offset.dotProduct(offset);

                    // push onto result vector when within given radius
                    if (d2 < r2) results.push_back ((**i).object);
                }
            }

        private:
            BruteForceProximityDatabase* bfpd;
            ContentType object;
            Vector3 position;
        };

        typedef std::vector<tokenType*> tokenVector;
        typedef typename tokenVector::const_iterator tokenIterator;    

        // allocate a token to represent a given client object in this database
        tokenType* allocateToken (ContentType parentObject)
        {
            return new tokenType (parentObject, *this);
        }

        // return the number of tokens currently in the database
        int getPopulation (void)
        {
            return (int) group.size();
        }
        
    private:
        // STL vector containing all tokens in database
        tokenVector group;
    };


    // ----------------------------------------------------------------------------
    // A AbstractProximityDatabase-style wrapper for the LQ bin lattice system
    template <class ContentType> class LQProximityDatabase : public AbstractProximityDatabase<ContentType>
    {
    public:
        LQProximityDatabase (const Vector3& center,
                             const Vector3& dimensions,
                             const Vector3& divisions)
        {
            const Vector3 halfsize (dimensions * 0.5f);
            const Vector3 origin (center - halfsize);

			m_LocalityQuery = new LocalityQuery();

			lq = m_LocalityQuery->lqCreateDatabase (origin.x, origin.y, origin.z, 
                                   dimensions.x, dimensions.y, dimensions.z,  
                                   (int) round (divisions.x),
                                   (int) round (divisions.y),
                                   (int) round (divisions.z));
        }

        // destructor
        virtual ~LQProximityDatabase ()
        {
            m_LocalityQuery->lqDeleteDatabase (lq);
            lq = nullptr;
        }

        // "token" to represent objects stored in the database
        class tokenType : public AbstractTokenForProximityDatabase<ContentType>
        {
        public:
            tokenType (ContentType parentObject, LQProximityDatabase& lqsd)
            {
				m_LocalityQuery = new LocalityQuery();
                m_LocalityQuery->lqInitClientProxy (&proxy, parentObject);
                lq = lqsd.lq;
            }

            virtual ~tokenType (void)
            {
                m_LocalityQuery->lqRemoveFromBin (&proxy);
            }

            // the client object calls this each time its position changes
            void updateForNewPosition (const Vector3& p)
            {
                m_LocalityQuery->lqUpdateForNewLocation (lq, &proxy, p.x, p.y, p.z);
            }

            // find all neighbors within the given sphere (as center and radius)
            void findNeighbors (const Vector3& center,
                                const float radius,
                                std::vector<ContentType>& results)
            {
                m_LocalityQuery->lqMapOverAllObjectsInLocality (lq, 
                                               center.x, center.y, center.z,
                                               radius,
                                               perNeighborCallBackFunction,
                                               (void*)&results);
            }

            // called by LQ for each clientObject in the specified neighborhood:
            // push that clientObject onto the ContentType vector in void*
            // clientQueryState
            // (parameter names commented out to prevent compiler warning from "-W")
            static void perNeighborCallBackFunction  (void* clientObject,
                                                      float /*distanceSquared*/,
                                                      void* clientQueryState)
            {
                typedef std::vector<ContentType> ctv;
                ctv& results = *((ctv*) clientQueryState);
                results.push_back ((ContentType) clientObject);
            }

#ifndef NO_LQ_BIN_STATS
            // Get statistics about bin populations: min, max and
            // average of non-empty bins.
            void getBinPopulationStats (int& min, int& max, float& average)
            {
                m_LocalityQuery->lqGetBinPopulationStats (lq, &min, &max, &average);
            }
#endif // NO_LQ_BIN_STATS

        private:
			LocalityQuery* m_LocalityQuery;
			LocalityQuery::lqClientProxy proxy;
			LocalityQuery::lqInternalDB* lq;
        };

        // allocate a token to represent a given client object in this database
        tokenType* allocateToken (ContentType parentObject)
        {
            return new tokenType (parentObject, *this);
        }

        // count the number of tokens currently in the database
        int getPopulation (void)
        {
            int count = 0;
            m_LocalityQuery->lqMapOverAllObjects (lq, counterCallBackFunction, &count);
            return count;
        }
        
        // (parameter names commented out to prevent compiler warning from "-W")
        static void counterCallBackFunction  (void* /*clientObject*/,
                                              float /*distanceSquared*/,
                                              void* clientQueryState)
        {
            int& counter = *(int*)clientQueryState;
            counter++;
        }


    private:
		LocalityQuery* m_LocalityQuery;
        LocalityQuery::lqInternalDB* lq;
    };

}
}



// ----------------------------------------------------------------------------
#endif // OPENSTEER_PROXIMITY_H
