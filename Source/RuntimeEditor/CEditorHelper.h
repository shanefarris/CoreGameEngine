#ifndef __METHODS_H__
#define __METHODS_H__

#include "Defines.h"
#include "EditorObjects.h"

#define PATH_MESH "SPHERE_1"
#define SOUND_BILLBOARD "SOUND_BILLBOARD_"
#define SPAWN_POINT_MESH "SPAWN_POINT"
#define LIGHT_EDITOR_MESH "LIGHT_EDITOR"

namespace Core
{
	class CPlayer;
	class CBuilding;
	class CGameObject;

namespace Editor
{
	class CEditorHelper
	{
	public:
		static ManualObject* Draw3D_Line(const Vector3& from, const Vector3& to, const ColourValue& Color, String& matName);
		static ManualObject* Draw3D_Lines(const Vector<Vector3>& from, const Vector<Vector3>& to, const ColourValue& Color, String& matName);

		static CGameObject* AddObstacleBox(const Vector3& Position);
		static CGameObject* AddObstacleSphere(const Vector3& Position);
		static void AddPathNodeShape(const Vector3& Position);
		static void AddAStarNodeShapes(const Vector<Vector3>& Positions);
		static void AddLightShape(Light* OgreLight);

		static CGameObject* FindObject(f32 Width, f32 Height);
		static bool FindSelected(f32 Width, f32 Height, SELECTED& Selected);
		static Vector3 FindY(f32 Width, f32 Height);

		static void CreateSoundBillBoard(const Vector3& Position);
		static void CreateSoundObject(const Vector3& Position, SOUND_OBJ& SoundObj);

		static Vector<Vector3> RandomMeshPlacerOnY_Terrain(String& GameObjectType, f32 Top, f32 Bottom, f32 Right, f32 Left, u32 Count);
		static void LoadSceneFile(String SceneFile);

	private:
		static Entity* FindSound(f32 Width, f32 Height);
		static CPlayer* FindPlayer(f32 Width, f32 Height);
		static CBuilding* FindBuilding(f32 Width, f32 Height);

	};

}
}

#endif // __METHODS_H__