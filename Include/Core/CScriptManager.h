#ifndef __CSCRIPTMANAGER_H__
#define __CSCRIPTMANAGER_H__

#include "Defines.h"

#ifdef COMPILE_SCRIPT
	#define CALL_VOIDFUNCVOID(Name) Core::CScriptManager::Instance()->VoidExecuteVoid(Name);
	#define CALL_VOIDFUNCFLOAT(Name, p1) Core::CScriptManager::Instance()->VoidExecuteFloat(Name, p1);
	#define CALL_VOIDFUNCCONSTCHAR(Name, p1) CScriptManager::Instance()->VoidExecuteConstChar(PLAYER_CREATED, p1);
	#define CALL_VOIDFUNCGAMEOBJECT(Name, p1) Core::CScriptManager::Instance()->VoidExecuteGameObject(Name, p1);
#else
	#define CALL_VOIDFUNCVOID(Name)
	#define CALL_VOIDFUNCFLOAT(Name, p1)
	#define CALL_VOIDFUNCCONSTCHAR(Name, p1)
	#define CALL_VOIDFUNCGAMEOBJECT(Name, p1)
#endif

#ifdef COMPILE_SCRIPT

extern "C" {
	#include "ToLua/lua.h"
	#include "ToLua/lualib.h"
	#include "ToLua/lauxlib.h"
}

namespace Core
{
	class CGameObject;

	// Game level events
	#define START					"OnStart"
	#define LOAD_LEVEL				"OnLoadLevel"
	#define UNLOAD_LEVEL			"OnUnLoadLevel"
	#define PRE_UPDATE_GAME			"OnPreUpdateGame"
	#define POST_UPDATE_GAME		"OnPostUpdateGame"
	#define PRE_UPDATE_GAMEOBJECTS	"OnPreUpdateGameObjects"
	#define PRE_UPDATE_PLAYERS		"OnPreUpdatePlayers"
	#define POST_UPDATE_PLAYERS		"OnPostUpdatePlayers"

	#define GAMEOBJECT_CREATED		"OnGameObjectCreated"
	#define GAMEOBJECT_REMOVED		"OnGameObjectRemoved"
	#define PLAYER_CREATED			"OnPlayerCreated"

	typedef int (*LuaFunctionType)(struct lua_State *pLuaState);

	class CORE_EXPORT CScriptManager
	{
	public:
		static CScriptManager* Instance();
		~CScriptManager();

		typedef lua_State ScriptState;
		
		ScriptState* GetScriptState() { return this->m_ScriptState; }

		bool RunScriptFile(const char* FileName);
		bool RunLuaString(const char* command);
		bool AddGlobalFunction(const char* functionName, LuaFunctionType function);
		void ReloadScripts();

		// Events
		void VoidExecuteVoid(const char* FuncName);
		s32	 IntExecuteIntInt(const char* FuncName, s32 p1, s32 p2);
		void VoidExecuteFloat(const char* FuncName, const f32& p1);
		void VoidExecuteConstChar(const char* FuncName, const char* PlayerName);
		void VoidExecuteGameObject(const char* FuncName, CGameObject* GameObject);

		// Types
		typedef void (*VoidExecuteVoid_Ptr)(void);
		typedef s32 (*IntExecuteIntInt_Ptr)(s32, s32);
		typedef void (*VoidExecuteFloat_Ptr)(const f32&);
		typedef void (*VoidExecuteConstChar_Ptr)(const char*);
		typedef void (*VoidExecuteGameObject_Ptr)(CGameObject*);

		void AddVoidFunctionVoid(const char* FuncName, VoidExecuteVoid_Ptr& Func);
		void AddIntFunctionIntInt(const char* FuncName, IntExecuteIntInt_Ptr& Func);
		void AddVoidFunctionFloat(const char* FuncName, VoidExecuteFloat_Ptr& Func);
		void AddVoidFunctionConstChar(const char* FuncName, VoidExecuteConstChar_Ptr& Func);
		void AddVoidFunctionGameObject(const char* FuncName, VoidExecuteGameObject_Ptr& Func);

	private:
		static CScriptManager* ScriptManager;
		CScriptManager();

		void ReportErrors(ScriptState* State, int Status);

		ScriptState* m_ScriptState;

		Map<String, VoidExecuteVoid_Ptr>		m_VoidFunctionsVoid;
		Map<String, IntExecuteIntInt_Ptr>		m_IntFunctionsIntInt;
		Map<String, VoidExecuteFloat_Ptr>		m_VoidFunctionsFloat;
		Map<String, VoidExecuteConstChar_Ptr>	m_VoidFunctionsConstChar;
		Map<String, VoidExecuteGameObject_Ptr>	m_VoidFunctionsGameObject;
	};
}
	
#endif // COMPILE_SCRIPT
#endif // __CSCRIPTMANAGER_H__