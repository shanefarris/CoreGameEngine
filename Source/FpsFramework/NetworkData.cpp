#if defined(COMPILE_NETWORK)

#include "NetworkData.h"

#include "OgreVector3.h"

using namespace RakNet;
using namespace Core::Network;

bool NetworkData::ReadString(String &Str, RakNet::BitStream& BitStream)
{
	bool succes = true;
	char chr = '0';

	Str.clear();

	while(succes && chr != '\0')
	{
		succes = BitStream.Serialize(false, chr);
		if(succes && chr != '\0')
			Str.push_back(chr);
	}

	return succes;
}

bool NetworkData::ReadVector3(Vector3& Vec, RakNet::BitStream& BitStream)
{
	float x, y, z;

	auto succes = BitStream.SerializeVector(false, x, y, z);

	Vec.x = x;
	Vec.y = y;
	Vec.x = z;

	return succes;
}

bool NetworkData::ReadMatrix4(Matrix4& Matrix, RakNet::BitStream& BitStream)
{
	//bool succes = true;
	//float var = 0;

	//for(int i = 0; succes && i < 16; i++)
	//{
	//	if(BitStream.Serialize(false, var))
	//		Matrix = var;
	//}

	return false;
}

bool NetworkData::WriteString(const String& Str, RakNet::BitStream& BitStream)
{
	BitStream.Write(Str.c_str(), (u32)Str.size() + 1);
	return true;
}

bool NetworkData::WriteVector3(const Vector3& Vec, RakNet::BitStream& BitStream)
{
	float x = Vec.x;
	float y = Vec.y;
	float z = Vec.z;

	BitStream.SerializeVector(true, x, y, z);

	return true;
}

bool NetworkData::WriteMatrix4(const Matrix4& Matrix, RakNet::BitStream& BitStream)
{
	//for(int i = 0; i < 16; i++)
	//	BitStream.Write(matrix(i));

	return false;
}

#endif