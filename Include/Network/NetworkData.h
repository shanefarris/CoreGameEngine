#ifndef NETWORK_DATA_H
#define NETWORK_DATA_H

#define BUFFLEN 2048

#include "RakNet/WindowsIncludes.h"
#include "Defines.h"
#include "RakNet/bitstream.h"

#define PROTOCOL_HEADER_SIZE 5

namespace Core
{
namespace Network
{
	class CORE_EXPORT NetworkData
	{
	public:

		enum MsgStatus
		{
			CONNECTION_REQUEST_ACCEPTED,
			CONNECTION_ATTEMPT_FAILED,
			ALREADY_CONNECTED,
			NEW_INCOMING_CONNECTION,
			NO_FREE_INCOMING_CONNECTIONS,
			DISCONNECTION_NOTIFICATION,
			CONNECTION_LOST,
			USER_PACKET,
			UNKNOWN_ID,
		};

		enum MsgType
		{
			TYPE_EMPTY,
			RECEIVED,
			SEND_SINGLE,
			SEND_ALL_BUT,
			SEND_ALL,
		};

		NetworkData(int maxSize = BUFFLEN);
		virtual ~NetworkData();

		bool Load(String Address, u16 Port, const char* Data, s32 Size, s32 Ping = -1);
		void Initialize(MsgType MessageType, bool isReliable = true, String Address = "", u16 Port = 0);

		char*		GetData() const;
		u32			GetSize() const { return m_Bitstream->GetNumberOfBytesUsed(); }
		u32			GetFullSize() const { return GetSize() + PROTOCOL_HEADER_SIZE; }
		MsgStatus	GetStatus() const;
		String		GetAddress() const { return m_Address; }
		u16			GetPort() const { return m_Port; }
		s32			GetPing() const { return m_Ping; }
		MsgType		GetMessageType() const { return m_MessageType; }
		bool		IsReliable() const { return isReliable; }

		int GetBytesRead() const { return m_Bitstream->GetReadOffset() / 8; }

		void SetAddress(u32 Address) { m_Address = Address; }
		void SetPort(u16 Port) { m_Port = Port; }

		template <class templateType> bool ReadVar(templateType &var);
		template <class templateType> bool ReadArray(templateType *arr, short &size);
		bool ReadString(String &str);
		bool ReadVector3(Vector3 &vector);
		bool ReadNormVector3(Vector3 &vector);
		bool ReadMatrix4(Matrix4 &matrix);

		template <class T> bool WriteVar(T Variable);
		template <class T> bool WriteArray(const T *DataArray, short Size);
		bool WriteString(const String &Str);
		bool WriteVector3(const Vector3 &Vec);
		bool WriteNormVector3(const Vector3 &Vec);
		bool WriteMatrix4(const Matrix4 &Mat);

	private:
		void Clear();

		RakNet::BitStream*	m_Bitstream;
		String				m_Address;
		u16					m_Port;
		s32					m_Ping;
		MsgType				m_MessageType;
		char*				m_Data;
		bool				isReliable;
		bool				isReadPermission;
		bool				isWritePermission;		
	};

	template <class T> bool NetworkData::ReadVar(T &var)
	{
		return m_Bitstream->Serialize(0, var);
	}

	template <class T> bool NetworkData::ReadArray(T *arr, short &size)
	{
		if(!m_Bitstream->Serialize(0, size))
			return false;

		for(short i = 0; succes && i < size; i++)
		{
			if(!m_Bitstream->Serialize(0, arr[i]))
				return false;
		}

		return true;
	}

	template <class T> bool NetworkData::WriteVar(T var)
	{
		return m_Bitstream->Serialize(1, var);
	}

	template <class T> bool NetworkData::WriteArray(const T *arr, short size)
	{
		if(!m_Bitstream->Serialize(1, size))
			return false;

		for(short i; i < size; i++)
		{
			if(!m_Bitstream->Serialize(1, arr[i]))
				return false;
		}

		return true;
	}

}
}

#endif // NETWORK_CLIENT_H