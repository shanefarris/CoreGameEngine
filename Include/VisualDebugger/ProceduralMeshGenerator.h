/*
-----------------------------------------------------------------------------
This source file is part of ogre-procedural

For the latest info, see http://code.google.com/p/ogre-procedural/

Copyright (c) 2010 Michael Broutin

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
-----------------------------------------------------------------------------
*/
#ifndef PROCEDURAL_MESH_GENERATOR_INCLUDED
#define PROCEDURAL_MESH_GENERATOR_INCLUDED
#include "Ogre.h"
#include "ProceduralRoot.h"
#include "ProceduralPlatform.h"

#include "CGameManager.h"

namespace Procedural
{
template <typename T>
class MeshGenerator
{
protected:
	Ogre::SceneManager* sceneMgr;
	float uTile;
	float vTile;

	bool enableNormals;
	unsigned int numTexCoordSet;

	Ogre::MaterialPtr CustomMaterial;
	Ogre::Technique* CustomTechnique;
public:

	Ogre::Entity* entity;
	Ogre::SceneNode* node;

	MeshGenerator() : uTile(1.f),
					  vTile(1.f),
					  enableNormals(true),
					  numTexCoordSet(1),
					  entity(nullptr), 
					  node(nullptr)
	{
		CustomMaterial = Ogre::MaterialManager::getSingleton().create("WireframeSingleMesh", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME); 
		CustomTechnique = CustomMaterial->createTechnique(); 
		CustomMaterial->getTechnique(0)->getPass(0)->setPolygonMode(Ogre::PM_WIREFRAME);

		sceneMgr = Core::CGameManager::Instance()->GetSceneManager();
		assert(sceneMgr && "Scene Manager must be set in Root");
	}

	Ogre::MeshPtr realizeMesh(const std::string& name)
	{
		Ogre::ManualObject * manual = sceneMgr->createManualObject(name);
		manual->begin("WireframeSingleMesh", Ogre::RenderOperation::OT_TRIANGLE_LIST);

		int offset=0;
		Ogre::AxisAlignedBox aabb;
		float radius(0.f);
		addToManualObject(manual, offset, radius, aabb);

		manual->end();
		Ogre::MeshPtr mesh = manual->convertToMesh(name);

		mesh->_setBounds( aabb, false );
		mesh->_setBoundingSphereRadius(radius);

		unsigned short src, dest;
		if (!mesh->suggestTangentVectorBuildParams(Ogre::VES_TANGENT, src, dest))
		{
			mesh->buildTangentVectors(Ogre::VES_TANGENT, src, dest);
		}

		return mesh;
	}
	
	Ogre::MeshPtr realizeMesh(const std::string& name, const Ogre::Vector3& Position)
	{
		Ogre::MeshPtr mesh = realizeMesh(name);

		entity = Core::CGameManager::Instance()->GetSceneManager()->createEntity(name);
		node = Core::CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode();
		entity->setQueryFlags(0);
		node->attachObject(entity);
		node->setPosition(Position);

		return mesh;
	}

	virtual void addToManualObject(Ogre::ManualObject* manual, int& offset, float& boundingRadius, Ogre::AxisAlignedBox& aabb)=0;

	inline T& setUTile(float uTile)
	{
		this->uTile = uTile;
		return static_cast<T&>(*this);
	}

	inline T & setVTile(float vTile)
	{
		this->vTile = vTile;
		return static_cast<T&>(*this);
	}

	inline T & setEnableNormals(bool enableNormals)
	{
		this->enableNormals = enableNormals;
		return static_cast<T&>(*this);
	}

	inline T & setNumTexCoordSet(unsigned int numTexCoordSet)
	{
		this->numTexCoordSet = numTexCoordSet;
		return static_cast<T&>(*this);
	}

};
//
}
#endif
