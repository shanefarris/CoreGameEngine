#ifndef __CBILLBOARD_SYSTEM_H__
#define __CBILLBOARD_SYSTEM_H__

#include "Defines.h"

namespace Core
{
	class CBillboardNode;
	class CBillboardNodeSet;
	class CBillboardManager;
	
	class CORE_EXPORT CBillboardManager
	{
	public:
		static CBillboardManager* Instance();
		
		~CBillboardManager();
		void Shutdown();

		void CreateBillboard(const String& Name, u32 Type, u32 PoolSize, const String& MaterialName, const f32& Width, const f32& Height);
		void Update(const f32& elapsedTime);
		void UpdateBillboard(const char* Name, s32 Id, const Vector3& Position);
		void HideBillboard(const char* Name, s32 Id);
		s32  ShowBillboard(const char* name, const Vector3& Position, const f32& Time);

	private:

		class CBillboardNode
		{
			friend class CBillboardManager;
			friend class CBillboardNodeSet;

		private:
			CBillboardNode();
			~CBillboardNode();

			Billboard*	bill;
			f32			liveTime;
		};

		class CBillboardNodeSet
		{
			friend class CBillboardManager;

		private:
			CBillboardNodeSet(int sz);
			~CBillboardNodeSet();
		
			void Update(const f32& elapsedTime);
			void Finalize(Ogre::SceneNode* parent);
			void IncCounter() { counter++; counter %= size; }
			CBillboardNode* GetCurrent() { return buffer[counter]; }

			BillboardSet*			set;
			Vector<CBillboardNode*> buffer;
			s32						counter;
			s32						size;
		};

		CBillboardManager();
		
		static CBillboardManager*		BillboardManager;		
		Map<String, CBillboardNodeSet*>	m_Sets;
		SceneNode*						m_BillNode;
	};
}

#endif // __CBILLBOARD_SYSTEM_H__