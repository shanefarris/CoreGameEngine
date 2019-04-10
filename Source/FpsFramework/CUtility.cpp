#include "CUtility.h"
#include <time.h>

#include "Defines.h"
#include "CGameManager.h"
#include "NavMesh/RecastInputGeom.h"

#include "OgreStringConverter.h"
#include "OgreEntity.h"
#include "OgreSubMesh.h"
#include "OgreSubEntity.h"
#include "OgreSkeletonInstance.h"
#include "OgreBone.h"
#include "OgreRay.h"
#include "OgreSceneManager.h"
#include "OgreSceneNode.h"

using namespace Core;

void CUtility::StringSplit(const String& s, const char delim, Vector<String>& Elements) 
{
	std::stringstream ss(s);
	String item;
	while(std::getline(ss, item, delim)) 
	{
		if(item != "")
			Elements.push_back(item);
	}
}

void CUtility::StringReplace(String& Source, const String& Find, const String& Replace) 
{
	size_t j; 
	for (;(j = Source.find(Find)) != String::npos;) 
	{ 
		Source.replace(j, Find.length(), Replace); 
	}
}

String& CUtility::LeftTrim(String& Source) 
{
	Source.erase(Source.begin(), std::find_if(Source.begin(), Source.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
	return Source;
}

String& CUtility::RightTrim(String& Source) 
{
	Source.erase(std::find_if(Source.rbegin(), Source.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), Source.end());
	return Source;
}

String& CUtility::Trim(String &Source) 
{
	return LeftTrim(RightTrim(Source));
}

void CUtility::StripString(char* instr, int from, char* outstr, int max)
{
	s32 instrlen = (s32)strlen(instr);	// get length of input string
	s32 outi = 0;						// index in output string

	// scan through entire input string
	for (int ini = from; ini < instrlen; ini++) 
	{
		outstr[outi] = instr[ini];
		outi++;

		// prevent stack smashing of output string
		if (outi == max - 1) 	
			break;
	}
	outstr[outi] = '\0';	// terminate output string
}

void CUtility::Sleep(u32 ms)
{
	clock_t goal = ms + clock();
	while (goal > clock());
}

u32 CUtility::RSHash()
{
	// This is not random, same value at least most of the time
	time_t seconds = time(0);
	u32 value = (u32)seconds / 3600;
	String str = StringConverter::toString(value);
	u32 b    = 378551;
	u32 a    = 63689;
	u32 hash = 0;

	for(u32 i = 0; i < str.length(); i++)
	{
		hash = hash * a + str[i];
		a    = a * b;
	}

	return hash;
}

s32 CUtility::SearchDirectory(Vector<String>& FilesFound, const String& SearchDir, const String& FilterExtension, bool Subdirectories)
{
	String     strFilePath;             // Filepath
	String     strPattern;              // Pattern
	String     strExtension;            // Extension
	HANDLE		hFile;					// Handle to file
	WIN32_FIND_DATA FileInformation;	// File information

	strPattern = SearchDir + "\\*.*";

	hFile = ::FindFirstFile(strPattern.c_str(), &FileInformation);
	if(hFile != INVALID_HANDLE_VALUE)
	{
		do
		{
			if(FileInformation.cFileName[0] != '.')
			{
				strFilePath.erase();
				strFilePath = SearchDir + "\\" + FileInformation.cFileName;

				if(FileInformation.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
				{
					if(Subdirectories)
					{
						// Search subdirectory
						s32 iRC = SearchDirectory(FilesFound, strFilePath, FilterExtension, Subdirectories);
						if(iRC)
							return iRC;
					}
				}
				else
				{
					// Check extension
					strExtension = FileInformation.cFileName;
					strExtension = strExtension.substr(strExtension.rfind(".") + 1);

					if(strExtension == FilterExtension)
					{
						// Save filename
						FilesFound.push_back(strFilePath);
					}
				}
			}
		} while(::FindNextFile(hFile, &FileInformation) == TRUE);

		// Close handle
		::FindClose(hFile);

		DWORD dwError = ::GetLastError();
		if(dwError != ERROR_NO_MORE_FILES)
			return dwError;
	}
	return 0;
}

bool CUtility::FileExists(const char* path)
{
#if WIN32
	DWORD fileAttr = GetFileAttributes(path);
	return (fileAttr != 0xFFFFFFFF);
#else
	return false;
#endif
}

#ifdef _DEBUG
void CUtility::RagdollInfo(String outFileName, SceneNode* characterSN)
{
	std::ofstream file(outFileName.c_str());
	if (file)
	{
		Entity* e=(Entity*)characterSN->getAttachedObject(0);
		SkeletonInstance* skeletonInst = e->getSkeleton();
		Skeleton::BoneIterator boneI=skeletonInst->getBoneIterator();

		file<<"Creating bone lenght information from:\n";
		file<<"Mesh name: "<<e->getMesh()->getName()<<"\n";
		file<<"Skeleton name: "<<skeletonInst->getName()<<"\n\n";

		while(boneI.hasMoreElements())
		{
			Bone* bone=boneI.getNext();
			String bName=bone->getName();

			if (bone->getChild(0))
			{
				Vector3 curr = bone->_getDerivedPosition();
				Vector3 next = bone->getChild(0)->_getDerivedPosition();

				Vector3 difference = next-curr;

				//length of bone
				Real lenght = difference.length();

				file<<bName<<"\t\t\t=\t"<<StringConverter::toString(lenght,3)<<"\n";
				if (!bone->getParent())
					file<<bName<<" is a Root Bone\n";
			}
		}
	}
} 
#endif

float CUtility::frandom01 (void)
{
	return (((float) rand ()) / ((float) RAND_MAX));
}

float CUtility::frandom2 (float lowerBound, float upperBound)
{
	return lowerBound + (frandom01 () * (upperBound - lowerBound));
}

f32 CUtility::GetHeightAt(SceneManager* sm, f32& X, f32& Z)
{
	f32 Y = 0.0f;
	static Ray updateRay;

	updateRay.setOrigin(Vector3(X, 9999, Z));
	updateRay.setDirection(Vector3::NEGATIVE_UNIT_Y);

	auto tsmMRaySceneQuery =  sm->createRayQuery(updateRay);
	auto qryResult = tsmMRaySceneQuery->execute();
	auto i = qryResult.begin();
	if (i != qryResult.end() && i->worldFragment)
	{
		Y = i->worldFragment->singleIntersection.y;
	}
	CORE_DELETE(tsmMRaySceneQuery);
	return Y;
}

bool CUtility::PointInTriangle2D(Vector3& P, Vector3& A, Vector3& B, Vector3& C)
{
	//no Y-coordinate
	P.y = 0;
	A.y = 0;
	B.y = 0;
	C.y = 0;

	// Compute vectors        
	Vector3 v0 = C - A;
	Vector3 v1 = B - A;
	Vector3 v2 = P - A;

	// Compute dot products
	float dot00 = v0.dotProduct(v0);
	float dot01 = v0.dotProduct(v1);
	float dot02 = v0.dotProduct(v2);
	float dot11 = v1.dotProduct(v1);
	float dot12 = v1.dotProduct(v2);

	// Compute barycentric coordinates
	float invDenom = 1 / (dot00 * dot11 - dot01 * dot01);
	float u = (dot11 * dot02 - dot01 * dot12) * invDenom;
	float v = (dot00 * dot12 - dot01 * dot02) * invDenom;

	// Check if point is in triangle
	return (u >= 0) && (v >= 0) && (u + v < 1);
}

void CUtility::GetMeshInformation(Entity* entity,
								  u32& VertexCount,
								  Vector3*& Vertices,
								  u32& IndexCount,
								  ul32*& Indices,
								  const Vector3 &Position,
								  const Quaternion &Orientation,
								  const Vector3& Scale)
{
	bool addedShared = false;
	u32 currentOffset = 0;
	u32 sharedOffset = 0;
	u32 nextOffset = 0;
	u32 indexOffset = 0;
	VertexCount = IndexCount = 0;
	auto mesh = entity->getMesh();

	bool useSoftwareBlendingVertices = entity->hasSkeleton();
	if (useSoftwareBlendingVertices)
	{
		entity->_updateAnimation();
	}

	// Calculate how many vertices and indices we're going to need
	for (u16 i = 0; i < mesh->getNumSubMeshes(); ++i)
	{
		auto submesh = mesh->getSubMesh(i);

		// We only need to add the shared vertices once
		if(submesh->useSharedVertices)
		{
			if( !addedShared )
			{
				VertexCount += (u32)mesh->sharedVertexData->vertexCount;
				addedShared = true;
			}
		}
		else
		{
			VertexCount += (u32)submesh->vertexData->vertexCount;
		}

		// Add the indices
		IndexCount += (u32)submesh->indexData->indexCount;
	}


	// Allocate space for the vertices and indices
	Vertices = new Vector3[VertexCount];
	Indices = new ul32[IndexCount];

	addedShared = false;

	// Run through the submeshes again, adding the data into the arrays
	for (u16 i = 0; i < mesh->getNumSubMeshes(); ++i)
	{
		auto submesh = mesh->getSubMesh(i);
		VertexData* vertexData;

		//When there is animation:
		if(useSoftwareBlendingVertices)
		{
			vertexData = submesh->useSharedVertices ? entity->_getSkelAnimVertexData() : entity->getSubEntity(i)->_getSkelAnimVertexData();
		}
		else
		{
			vertexData = submesh->useSharedVertices ? mesh->sharedVertexData : submesh->vertexData;
		}

		if((!submesh->useSharedVertices)||(submesh->useSharedVertices && !addedShared))
		{
			if(submesh->useSharedVertices)
			{
				addedShared = true;
				sharedOffset = currentOffset;
			}

			auto posElem = vertexData->vertexDeclaration->findElementBySemantic(Ogre::VES_POSITION);
			auto vbuf = vertexData->vertexBufferBinding->getBuffer(posElem->getSource());
			auto vertex = static_cast<u8*>(vbuf->lock(HardwareBuffer::HBL_READ_ONLY));

			f32* vertexPostion = nullptr;
			for(u32 j = 0; j < vertexData->vertexCount; ++j, vertex += vbuf->getVertexSize())
			{
				posElem->baseVertexPointerToElement(vertex, &vertexPostion);
				Vector3 pt(vertexPostion[0], vertexPostion[1], vertexPostion[2]);
				Vertices[currentOffset + j] = (Orientation * (pt * Scale)) + Position;
			}

			vbuf->unlock();
			nextOffset += (u32)vertexData->vertexCount;
		}

		auto indexData = submesh->indexData;
		auto ibuf = indexData->indexBuffer;
		auto numTris = indexData->indexCount / 3;
		bool use32bitindexes = (ibuf->getType() == HardwareIndexBuffer::IT_32BIT);

		auto pLong = static_cast<ul32*>(ibuf->lock(HardwareBuffer::HBL_READ_ONLY));
		auto pShort = reinterpret_cast<ul32*>(pLong);


		u32 offset = (submesh->useSharedVertices)? sharedOffset : currentOffset;
		u32 index_start = (u32)indexData->indexStart;
		u32 last_index = (u32)(numTris * 3 + index_start);

		if (use32bitindexes)
		{
			for (u32 k = index_start; k < last_index; ++k)
			{ 
				Indices[indexOffset++] = pLong[k] + static_cast<ul32>(offset); 
			}
		}
		else
		{
			for (u32 k = index_start; k < last_index; ++k)
			{ 
				Indices[indexOffset++] = static_cast<ul32>(pShort[k]) + static_cast<ul32>(offset); 
			}
		}

		ibuf->unlock();
		currentOffset = nextOffset;
	}
}

bool CUtility::RayQueryPointInScene(Ray& ray, ul32 queryMask, Vector3 &result, MovableObject **foundMovable)
{
	// TODO: destroy queries using scenemgr::destroyRayQuery or reuse one query object by storing it in a member variable
	auto rayScnQuery =  CGameManager::Instance()->GetSceneManager()->createRayQuery(Ogre::Ray(), queryMask);

	rayScnQuery->setRay(ray);
	auto query_result = rayScnQuery->execute();

	// At this point we have raycast to a series of different objects bounding boxes. We need to test these different objects to see which is the first polygon hit.
	// there are some minor optimizations (distance based) that mean we wont have to check all of the objects most of the time, but the worst case scenario is that
	// we need to test every triangle of every object.
	auto closest_distance = -1.0f;
	Vector3 closest_result;
	MovableObject* closest_movable;
	for (auto qr_idx = 0; qr_idx < query_result.size(); qr_idx++)
	{
		// Stop checking if we have found a raycast hit that is closer than all remaining entities
		if ((closest_distance >= 0.0f) && (closest_distance < query_result[qr_idx].distance))
		{
			break;
		}

		// Only check this result if its a hit against an entity
		if ((query_result[qr_idx].movable != nullptr) &&
			((query_result[qr_idx].movable->getMovableType().compare("Entity") == 0)
			||query_result[qr_idx].movable->getMovableType().compare("ManualObject") == 0))
		{
			// mesh data to retrieve
			size_t vertex_count;
			size_t index_count;
			Vector3 *vertices;
			ul32* indices;

			// Get the mesh information
			if(query_result[qr_idx].movable->getMovableType().compare("Entity") == 0) 
			{
				// For entities get the entity to check
				auto *pentity = static_cast<Ogre::Entity*>(query_result[qr_idx].movable);

				AI::NavMesh::InputGeom::getMeshInformation(pentity->getMesh(), vertex_count, vertices, index_count, indices,
					pentity->getParentNode()->_getDerivedPosition(),
					pentity->getParentNode()->_getDerivedOrientation(),
					pentity->getParentNode()->_getDerivedScale());
			} 
			else 
			{
				// For manualObjects get the entity to check
				auto *pmanual = static_cast<Ogre::ManualObject*>(query_result[qr_idx].movable);

				AI::NavMesh::InputGeom::getManualMeshInformation(pmanual, vertex_count, vertices, index_count, indices,
					pmanual->getParentNode()->_getDerivedPosition(),
					pmanual->getParentNode()->_getDerivedOrientation(),
					pmanual->getParentNode()->_getDerivedScale());
			}

			// Test for hitting individual triangles on the mesh
			bool new_closest_found = false;
			for (int i = 0; i < static_cast<int>(index_count); i += 3)
			{
				// Check for a hit against this triangle
				std::pair<bool, f32> hit = Math::intersects(ray, 
															vertices[indices[i]], 
															vertices[indices[i+1]], vertices[indices[i + 2]], true, false);

				// If it was a hit check if its the closest
				if (hit.first)
				{
					if ((closest_distance < 0.0f) || (hit.second < closest_distance))
					{
						// this is the closest so far, save it off
						closest_distance = hit.second;
						new_closest_found = true;
					}
				}
			}

			// Free the verticies and indicies memory
			delete[] vertices;
			delete[] indices;

			// If we found a new closest raycast for this object, update the closest_result before moving on to the next object.
			if (new_closest_found)
			{
				closest_result = ray.getPoint(closest_distance);
				if(query_result[qr_idx].movable != NULL)
					closest_movable = query_result[qr_idx].movable;
			}
		}
	}

	// Return the result
	if (closest_distance >= 0.0f)
	{
		// raycast success
		result = closest_result;
		*foundMovable = closest_movable;
		return (true);
	}
	else
	{
		// raycast failed
		return (false);
	}

}