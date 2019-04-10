#if defined(COMPILE_NETWORK)

#ifndef NETWORK_DATA_H
#define NETWORK_DATA_H

#define BUFFLEN 2048

#include "RakNet/WindowsIncludes.h"
#include "Defines.h"
#include "RakNet/bitstream.h"

#define PROTOCOL_HEADER_SIZE 5

namespace Ogre
{
	class Vector3;
	class Matrix4;
}

namespace Core
{
namespace Network
{
	class NetworkData
	{
	public:
		NetworkData() { };
		virtual ~NetworkData() { };

		template <class T> bool ReadVar(T& Var, RakNet::BitStream& BitStream);
		template <class T> bool ReadArray(T *Arry, const u32& Size, RakNet::BitStream& BitStream);
		bool ReadString(String &Str, RakNet::BitStream& BitStream);
		bool ReadVector3(Vector3 &Vec, RakNet::BitStream& BitStream);
		bool ReadNormVector3(Vector3& Vec, RakNet::BitStream& BitStream);
		bool ReadMatrix4(Matrix4 &Matrix, RakNet::BitStream& BitStream);

		template <class T> bool WriteVar(const T& Var, RakNet::BitStream& BitStream);
		template <class T> bool WriteArray(const T* DataArray, u32& Size, RakNet::BitStream& BitStream);
		bool WriteString(const String &Str, RakNet::BitStream& BitStream);
		bool WriteVector3(const Vector3 &Vec, RakNet::BitStream& BitStream);
		bool WriteNormVector3(const Vector3 &Vec, RakNet::BitStream& BitStream);
		bool WriteMatrix4(const Matrix4 &Mat, RakNet::BitStream& BitStream);

	};

	template <class T> bool NetworkData::ReadVar(T& Var, RakNet::BitStream& BitStream)
	{
		return Bitstream.Serialize(false, Var);
	}

	template <class T> bool NetworkData::ReadArray(T *Arry, const u32& Size, RakNet::BitStream& BitStream)
	{
		if(!Bitstream.Serialize(false, Size))
			return false;

		for(u32 i = 0; i < size; i++)
		{
			if(!Bitstream.Serialize(false, Arry[i]))
				return false;
		}

		return true;
	}

	template <class T> bool NetworkData::WriteVar(const T& Var, RakNet::BitStream& BitStream)
	{
		return Bitstream.Serialize(true, Var);
	}

	template <class T> bool NetworkData::WriteArray(const T* DataArray, u32& Size, RakNet::BitStream& BitStream)
	{
		if(!Bitstream.Serialize(true, Size))
			return false;

		for(u32 i; i < size; i++)
		{
			if(!Bitstream.Serialize(true, Arry[i]))
				return false;
		}

		return true;
	}

}
}

#endif // NETWORK_CLIENT_H

#endif