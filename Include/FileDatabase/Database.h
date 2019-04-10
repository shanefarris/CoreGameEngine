#ifndef _DATABASE_H_SQLITE
#define _DATABASE_H_SQLITE

#ifdef _WIN32
#include <windows.h>
#else
#include <pthread.h>
#endif
#include <string>
#include <vector>
#ifdef WIN32
typedef unsigned __int64 uint64_t;
typedef __int64 int64_t;
#pragma warning(push)
#pragma warning(disable:4251)

#ifdef CORE_DLL
	#define CORE_EXPORT __declspec(dllexport)
#else
	#define CORE_EXPORT __declspec(dllimport)
#endif
#else
#include <stdint.h>
#endif

#ifdef SQLITEW_NAMESPACE
namespace SQLITEW_NAMESPACE {
#endif


class IError;
class Query;
class Mutex;


/** Connection information and pool. */
class CORE_EXPORT Database 
{
public:
	/** Mutex container class, used by Lock. 
		\ingroup threading */
	class CORE_EXPORT Mutex {
	public:
		Mutex();
		~Mutex();
		void Lock();
		void Unlock();
	private:
#ifdef _WIN32
		HANDLE m_mutex;
#else
		pthread_mutex_t m_mutex;
#endif
	};
private:
	/** Mutex helper class. */
	class Lock {
	public:
		Lock(Mutex& mutex,bool use);
		~Lock();
	private:
		Mutex& m_mutex;
		bool m_b_use;
	};
public:
	/** Connection pool struct. */
	struct OPENDB {
		OPENDB() : busy(false) {}
		sqlite3 *db;
		bool busy;
	};
	typedef std::vector<OPENDB *> opendb_v;

public:
	/** Use file */
	Database(const std::string& database,
		IError * = nullptr);

	/** Use file + thread safe */
	Database(Mutex& ,const std::string& database,
		IError * = nullptr);

	virtual ~Database();

	/** try to establish connection with given host */
	bool Connected();

	void RegErrHandler(IError *);
	void error(Query&,const char *format, ...);
	void error(Query&,const std::string& );

	/** Request a database connection.
The "grabdb" method is used by the Query class, so that each object instance of Query gets a unique
database connection. I will reimplement your connection check logic in the Query class, as that's where
the database connection is really used.
It should be used something like this.
{
		Query q(db);
		if (!q.Connected())
			 return false;
		q.execute("delete * from user"); // well maybe not
}

When the Query object is deleted, then "freedb" is called - the database connection stays open in the
m_opendbs vector. New Query objects can then reuse old connections.
	*/
	OPENDB *grabdb();
	void freedb(OPENDB *odb);

	/** Escape string - change all ' to ''. */
	std::string safestr(const std::string& );
	/** Make string xml safe. */
	std::string xmlsafestr(const std::string& );

	/** Convert string to 64-bit integer. */
	int64_t a2bigint(const std::string& );
	/** Convert string to unsigned 64-bit integer. */
	uint64_t a2ubigint(const std::string& );

private:
	Database(const Database& ) : m_mutex(m_mutex) {}
	Database& operator=(const Database& ) { return *this; }
	void error(const char *format, ...);
	//
	std::string database;
	opendb_v m_opendbs;
	IError *m_errhandler;
	bool m_embedded;
	Mutex& m_mutex;
	bool m_b_use_mutex;
};

#pragma warning(pop)

#ifdef SQLITEW_NAMESPACE
} // namespace SQLITEW_NAMESPACE {
#endif

#endif // _DATABASE_H
