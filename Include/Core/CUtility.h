#ifndef __CUTILITY_H__
#define __CUTILITY_H__

#include "Defines.h"

namespace Ogre
{
	class SceneNode;
	class SceneManager;
}

namespace Core
{
	class CORE_EXPORT CUtility
	{
	public:
		static void StringSplit(const String& s, const char delim, Vector<String>& Elements);

		static void StringReplace(String& Source, const String& Find, const String& Replace);

		static String& LeftTrim(String& Source);

		static String& RightTrim(String& Source);

		static String& Trim(String& Source);

		// strip a string out of another string from an index to a max size, including whitespace
		static void StripString(char* instr, int from, char* outstr, int max);

		static void Sleep(u32 ms);

		static u32 RSHash();

		static s32 SearchDirectory(Vector<String>& FilesFound, const String& SearchDir, const String& FilterExtension, bool Subdirectories);

		static bool FileExists(const char* path);

#ifdef _DEBUG
		void RagdollInfo(String outFileName, SceneNode* characterSN);
#endif

		// ----------------------------------------------------------------------------
		// Random number utilities
		// Returns a float randomly distributed between 0 and 1
		static f32 frandom01 (void);

		// Returns a float randomly distributed between lowerBound and upperBound
		static f32 frandom2(f32 lowerBound, f32 upperBound);

		__declspec(deprecated("GetHeightAt is deprecated (this is used for older heightmaps."))
			static f32 GetHeightAt(SceneManager* sm, f32& X, f32& Z);

		static bool PointInTriangle2D(Vector3& P, Vector3& A, Vector3& B, Vector3& C);

		// Mesh Information
		static void GetMeshInformation(Entity* entity, u32& vertexCount, Vector3*& Vertices, u32 &index_count, ul32* &indices, 
			const Vector3 &position, const Quaternion &orient, const Vector3 &scale);

		/**
		* Calculate an intersection point of a ray with objects in the scene.
		* ray is the ray which is intersected with the scene
		* queryMask helps to include or exclude objects from the query
		* result is the point in the scene that was hit, in world-space coordinates
		* foundMovable is the entity or object that was hit
		**/
		static bool RayQueryPointInScene(Ray& ray, ul32 queryMask, Vector3& result, MovableObject **foundMovable);
	};
}

#endif // __CUTILITY_H__