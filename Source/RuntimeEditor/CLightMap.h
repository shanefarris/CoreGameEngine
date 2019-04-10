#if 0
#pragma once

#include "Defines.h"

#include <utility>
#include "../CImg-1.5.4/CImg.h"

#include "OgreEntity.h"
#include "OgreMaterial.h"
#include "OgreTexture.h"
#include "OgreResource.h"

//namespace cimg_library
//{
//	template<typename T> struct CImg;
//};

class CORE_EXPORT CLightMap : public ManualResourceLoader
{
public:
	CLightMap(SubEntity* pSubEntity, Real PixelsPerUnit = 0, int iTexSize = 512, bool bDebugLightmaps = false);
	~CLightMap(void);

	void loadResource(Resource *resource);
	String GetName();
	static void ResetCounter();

	struct SortCoordsByDistance
	{
		bool operator()(std::pair<int, int> &left, std::pair<int, int> &right)
		{
			return (left.first*left.first + left.second*left.second) < 
				(right.first*right.first + right.second*right.second);
		}
	};

protected:
	void LightTriangle(const Vector3 &P1, const Vector3 &P2, const Vector3 &P3,
		const Vector3 &N1, const Vector3 &N2, const Vector3 &N3,
		const Vector2 &T1, const Vector2 &T2, const Vector2 &T3);
	uint8 GetLightIntensity(const Vector3 &Position, const Vector3 &Normal);
	bool CalculateLightMap();
	void AssignMaterial();
	void CreateTexture();
	void FillInvalidPixels();
	static void BuildSearchPattern();

	/// Convert between texture coordinates given as reals and pixel coordinates given as integers
	inline int GetPixelCoordinate(Real TextureCoord);
	inline Real GetTextureCoordinate(int iPixelCoord);

	/// Calculate coordinates of P in terms of P1, P2 and P3
	/// P = x*P1 + y*P2 + z*P3
	/// If any of P.x, P.y or P.z are negative then P is outside of the triangle
	Vector3 GetBarycentricCoordinates(const Vector2 &P1, const Vector2 &P2, const Vector2 &P3, const Vector2 &P);
	/// Get the surface area of a triangle
	Real GetTriangleArea(const Vector3 &P1, const Vector3 &P2, const Vector3 &P3);

	TexturePtr m_Texture;
	MaterialPtr m_Material;
	SubEntity* m_pSubEntity;
	cimg_library::CImg<unsigned char>* m_LightMap;
	String m_LightMapName;
	int m_iTexSize;
	int m_iCoordSet;
	static int m_iLightMapCounter;
	Real m_PixelsPerUnit;
	static Vector<std::pair<int, int>> m_SearchPattern;
	bool m_bDebugLightmaps;
};

int CLightMap::GetPixelCoordinate(Real TextureCoord)
{
	int iPixel = TextureCoord*m_iTexSize;
	if (iPixel < 0)
		iPixel = 0;
	if (iPixel >= m_iTexSize)
		iPixel = m_iTexSize-1;
	return iPixel;
}

Real CLightMap::GetTextureCoordinate(int iPixelCoord)
{
	return (Real(iPixelCoord)+0.5)/Real(m_iTexSize);
}

class CEntityLightMap
{
public:
	CEntityLightMap(Entity* pEntity, Real PixelsPerUnit = 0, int iTexSize = 512, bool bDebugLightmaps = false)
	{
		int i, iNumSubEntities = pEntity->getNumSubEntities();
		for (i=0; i<iNumSubEntities; ++i)
		{
			CLightMap* LightMap(new CLightMap(pEntity->getSubEntity(i), PixelsPerUnit, iTexSize, bDebugLightmaps));
			m_LightMaps.push_back(LightMap);
		}
	}

protected:
	Vector<CLightMap*> m_LightMaps;
};

#endif