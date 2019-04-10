#ifndef _OGREODEDEBUGOBJECT_H_
#define _OGREODEDEBUGOBJECT_H_

#include "PreReqs.h"
#include "OgreSimpleRenderable.h"

namespace Ode
{
    //------------------------------------------------------------------------------------------------
	class DebugLines:public Ogre::SimpleRenderable
	{
	public:
		DebugLines(void);
		~DebugLines(void);

		void addLine(const Vector3 &start,const Vector3 &end)
		{
			clear();

			_points.push_back(start);
			_points.push_back(end);
		}
		void addLine(Ogre::Real start_x, Ogre::Real start_y, Ogre::Real start_z, 
            Ogre::Real end_x, Ogre::Real end_y, Ogre::Real end_z)
		{
			addLine(Vector3(start_x,start_y,start_z),Vector3(end_x,end_y,end_z));
		}
		void draw();
		void clear();

		Ogre::Real getSquaredViewDepth(const Ogre::Camera *cam) const;
		Ogre::Real getBoundingRadius(void) const;

	protected:

		Vector3Array _points;
		bool _drawn;

		static bool _materials_created;
	};
	//------------------------------------------------------------------------------------------------
	class DebugObject:public DebugLines
	{
	public:
		enum Mode
		{
			Mode_Unknown,
			Mode_Enabled,
			Mode_Disabled,
			Mode_Static
		};

	public:
        DebugObject(DebugObject::Mode mode = DebugObject::Mode_Enabled);
		virtual ~DebugObject();

		void setMode(DebugObject::Mode mode);

	protected:
		DebugObject::Mode _mode;
	};
	//------------------------------------------------------------------------------------------------
	class BoxDebugObject:public DebugObject
	{
	public:
		BoxDebugObject(const Vector3& size);
		virtual ~BoxDebugObject();
	};
	//------------------------------------------------------------------------------------------------
	class SphereDebugObject:public DebugObject
	{
	public:
		SphereDebugObject(Ogre::Real radius);
		virtual ~SphereDebugObject();
	};
	//------------------------------------------------------------------------------------------------
	class CapsuleDebugObject:public DebugObject
	{
	public:
		CapsuleDebugObject(Ogre::Real radius, Ogre::Real length);
		virtual ~CapsuleDebugObject();
	};
	//------------------------------------------------------------------------------------------------
	class CylinderDebugObject:public DebugObject
	{
	public:
		CylinderDebugObject(Ogre::Real radius, Ogre::Real length);
		virtual ~CylinderDebugObject();
	};
	//------------------------------------------------------------------------------------------------
	class TriangleMeshDebugObject:public DebugObject
	{
	public:
		TriangleMeshDebugObject(int vertex_count);
		virtual ~TriangleMeshDebugObject();

		void beginDefinition();
		void setVertex(int index, const Vector3& vertex);
		void endDefinition();
	};
	//------------------------------------------------------------------------------------------------
	class RayDebugObject:public DebugObject
	{
	public:
		RayDebugObject(const Vector3& start,const Vector3& direction,const Ogre::Real length);
		void setDefinition(const Vector3& start,const Vector3& direction,const Ogre::Real length);
		virtual ~RayDebugObject();
	};
}

#endif
