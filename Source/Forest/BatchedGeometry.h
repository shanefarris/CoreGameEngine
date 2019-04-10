//A "lightweight" version of StaticGeometry, which gives you a little more control over the batch materials, etc.
#ifndef __BatchedGeometry_H__
#define __BatchedGeometry_H__

#include "Defines.h"
#include <OgreMovableObject.h>

namespace Forests
{
	class BatchedGeometry: public MovableObject
	{
	public:
		BatchedGeometry(SceneManager *mgr, SceneNode *rootSceneNode);
		~BatchedGeometry();

		virtual void addEntity(Entity *ent, const Vector3 &position, const Quaternion &orientation = Quaternion::IDENTITY, const Vector3 &scale = Vector3::UNIT_SCALE, const ColourValue &color = ColourValue::White);
		void build();
		void clear();

		Vector3 _convertToLocal(const Vector3 &globalVec) const;

		void _notifyCurrentCamera(Camera *cam);
		void _updateRenderQueue(RenderQueue *queue);
		bool isVisible();
		const AxisAlignedBox &getBoundingBox(void) const { return bounds; }
		f32 getBoundingRadius(void) const { return radius; }
		const String &getMovableType(void) const { static String t = "BatchedGeometry"; return t; }

		void visitRenderables(Renderable::Visitor* visitor, bool debugRenderables) {}

		class SubBatch: public Renderable
		{
		public:
			SubBatch(BatchedGeometry *parent, SubEntity *ent);
			~SubBatch();

			void addSubEntity(SubEntity *ent, const Vector3 &position, const Quaternion &orientation, const Vector3 &scale, const ColourValue &color = ColourValue::White, void* userData = nullptr);
			virtual void build();
			void clear();
		
			void setMaterial(MaterialPtr &mat);
			void setMaterialName(const String &mat);
			inline String getMaterialName() const;

			void addSelfToRenderQueue(RenderQueue *queue, uint8 group);
			void getRenderOperation(RenderOperation& op);
			f32 getSquaredViewDepth(const Camera* cam) const;
			const LightList& getLights(void) const;

			Technique *getTechnique() const;
			const MaterialPtr &getMaterial(void) const;
			void getWorldTransforms(Matrix4* xform) const;
			const Quaternion& getWorldOrientation(void) const;
			const Vector3& getWorldPosition(void) const;
			bool castsShadows(void) const;

			VertexData *vertexData;
			IndexData *indexData;

		private:
			// This function is used to make a single clone of materials used, since the materials
			// will be modified by the batch system (and it wouldn't be good to modify the original materials
			// that the user may be using somewhere else).
			Material *getMaterialClone(Material &mat);

			Technique *bestTechnique;	//This is recalculated every frame

		protected:
			bool built;
			bool requireVertexColors;
			SubMesh *meshType;
			BatchedGeometry *parent;
			MaterialPtr material;
		
			// A structure defining the desired position/orientation/scale of a batched mesh. The
			// SubMesh is not specified since that can be determined by which MeshQueue this belongs to.
			struct QueuedMesh
			{
				SubMesh *mesh;
				Vector3 position;
				Quaternion orientation;
				Vector3 scale;
				ColourValue color;
				void* userData;
			};
			typedef std::vector<QueuedMesh>::iterator MeshQueueIterator;
			typedef std::vector<QueuedMesh> MeshQueue;
			MeshQueue meshQueue;	//The list of meshes to be added to this batch
		};


	private:
		f32 radius;

		SceneManager *sceneMgr;
		SceneNode *sceneNode, *parentSceneNode;

		f32 minDistanceSquared;
		bool withinFarDistance;


	protected:
		static void extractVertexDataFromShared(MeshPtr mesh);

		String getFormatString(SubEntity *ent);
		typedef std::map<String, SubBatch*> SubBatchMap;	//Stores a list of GeomBatch'es, using a format string (generated with getGeometryFormatString()) as the key value
		SubBatchMap subBatchMap;
		Vector3 center;	
		AxisAlignedBox bounds;
		bool boundsUndefined;

		bool built;

	public:
		typedef MapIterator<SubBatchMap> SubBatchIterator;
		SubBatchIterator getSubBatchIterator() const;
	};


}

#endif
