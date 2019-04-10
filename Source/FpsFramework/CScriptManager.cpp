#include "CScriptManager.h"
#ifdef COMPILE_SCRIPT
#include "Scripting/GeneralFunctions.hpp"
#include "CGameManager.h"
#include "IO/CoreLogging.h"

#include "ToLua/tolua++.h"
#include "Scripting/Core_lua.h"

using namespace Core;

int lgLuaRunFile(lua_State *L)
{
	CScriptManager::Instance()->RunScriptFile( luaL_checkstring(L, 1) );
	return 0;
}

CScriptManager* CScriptManager::ScriptManager = nullptr;

CScriptManager* CScriptManager::Instance()
{
	if(ScriptManager == nullptr)
		ScriptManager = new CScriptManager();
	return ScriptManager;
}

CScriptManager::CScriptManager()
{
	m_ScriptState = 0;
	// initialize Lua
	m_ScriptState = lua_open();

	// load Lua base libraries
	luaL_openlibs(m_ScriptState);

	// Initialize Core libraries
	//tolua_IO_open(m_ScriptState);
	//tolua_OverLays_open(m_ScriptState);
	tolua_Core_open(m_ScriptState);

	// Load default scripts
	luaL_dofile(m_ScriptState, "Entry.script");
	luaL_dofile(m_ScriptState, "Player.script");
	luaL_dofile(m_ScriptState, "AI.script");
	luaL_dofile(m_ScriptState, "GUI.script");
	luaL_dofile(m_ScriptState, "RuntimeEditor.script");

	// Add default scripting hooks for Framework
	void(*func1)(void) = &OnPreUpdatePlayers;
	AddVoidFunctionVoid("PreUpdatePlayer", func1);

	void(*func2)(void) = &OnPostUpdatePlayers;
	AddVoidFunctionVoid("PostUpdatePlayer", func2);

	// Game events
	void(*func3)(void) = &OnStart;
	AddVoidFunctionVoid("Start", func3);

	void(*func4)(void) = &OnLoadLevel;
	AddVoidFunctionVoid("LoadLevel", func4);

	void(*func5)(void) = &OnUnLoadLevel;
	AddVoidFunctionVoid("UnLoadLevel", func5);

	void(*func6)(const f32&) = &OnPreUpdateGame;
	AddVoidFunctionFloat("PreUpdateGame", func6);

	void(*func7)(const f32&) = &OnPostUpdateGame;
	AddVoidFunctionFloat("PostUpdateGame", func7);

	// Game Object events
	void(*func8)(CGameObject*) = &OnGameObjectCreate;
	AddVoidFunctionGameObject("GameObjectCreated", func8);

	void(*func9)(void) = &OnGameObjectsPreUpdate;
	AddVoidFunctionVoid("GameObjectsPreUpdate", func9);

	void(*func10)(CGameObject*) = &OnGameObjectRemoved;
	AddVoidFunctionGameObject("GameObjectRemoved", func10);

	// Add default scripting hooks for Runtime editor
	void(*func11)(const char*) = &OnPlayerCreate;
	AddVoidFunctionConstChar("OnPlayerCreate", func11);

	// Load default functions for lua scripts
	AddGlobalFunction("RunFile", lgLuaRunFile);		// is like an #include for lua
}

CScriptManager::~CScriptManager()
{
	try
	{
		if(m_ScriptState)
			lua_close(m_ScriptState);
	
		m_ScriptState = nullptr;

		CORE_LOG("Lua Manager successfuly shutdown.");
	}
	catch(std::exception& e)
	{
		CORE_ASSERT(false);
		throw(e);
	}
	catch(...)
	{
		throw("Error in ~CScriptManager()");
	}
}

void CScriptManager::ReportErrors(ScriptState* State, int Status)
{
	if (Status != 0)
	{
		std::string s = lua_tostring(State, -1);
		std::cerr << "-- " << s << std::endl;
		lua_pop(State, 1);
	}
}

bool CScriptManager::RunScriptFile(const char* FileName)
{
	CORE_LOG("Running Lua file: %s.", FileName);

	String fileAndPath;
	fileAndPath.assign(CGameManager::Instance()->GetScriptPath());
	fileAndPath.append(FileName);

	if (0 != luaL_loadfile(m_ScriptState, fileAndPath.c_str()))
	{
		CORE_ERR( "Culd not load Lua file \"%s\", Lua error:\n\t%s", fileAndPath.c_str(), luaL_checkstring(m_ScriptState, -1) );
		return false;
	}

	if (0 != lua_pcall(m_ScriptState, 0, LUA_MULTRET, 0))
	{
		CORE_LOG( "Error while running Lua file \"%s\", Lua error:\n\t%s", fileAndPath.c_str(), luaL_checkstring(m_ScriptState, -1) );
		return false;
	}

	return true;
}

bool CScriptManager::RunLuaString(const char* command)
{
	if (0 != luaL_loadbuffer(m_ScriptState, command, strlen(command), nullptr))
	{
		CORE_LOG( "Error while loading Lua command \"%s\", Lua error:\n\t%s", command, luaL_checkstring(m_ScriptState, -1) );
		return false;
	}
	if (0 != lua_pcall(m_ScriptState, 0, LUA_MULTRET, 0))
	{
		CORE_LOG( "Error while running Lua command \"%s\", Lua error:\n\t%s", command, luaL_checkstring(m_ScriptState, -1) );
		return false;
	}

	return true;
}

bool CScriptManager::AddGlobalFunction(const char* functionName, LuaFunctionType function)
{
	lua_register(m_ScriptState, functionName, function);
	return true;
}

void CScriptManager::ReloadScripts()
{
	// Load default scripts
	luaL_dofile(m_ScriptState, "Entry.script");
	luaL_dofile(m_ScriptState, "Player.script");
	luaL_dofile(m_ScriptState, "AI.script");
	luaL_dofile(m_ScriptState, "GUI.script");
	luaL_dofile(m_ScriptState, "RuntimeEditor.script");
}

// Void, Void methods
void CScriptManager::AddVoidFunctionVoid(const char* FuncName, VoidExecuteVoid_Ptr& Func)
{
	if(m_VoidFunctionsVoid.find(FuncName) == m_VoidFunctionsVoid.end())
	{
		m_VoidFunctionsVoid[FuncName] = Func;
	}
}

void CScriptManager::VoidExecuteVoid(const char* FuncName)
{
	if(m_VoidFunctionsVoid.find(FuncName) != m_VoidFunctionsVoid.end())
	{
		m_VoidFunctionsVoid[FuncName]();
	}
}

// Int, Int Int methods
void CScriptManager::AddIntFunctionIntInt(const char* FuncName, IntExecuteIntInt_Ptr& Func)
{
	if(m_IntFunctionsIntInt.find(FuncName) == m_IntFunctionsIntInt.end())
	{
		m_IntFunctionsIntInt[FuncName] = Func;
	}
}

s32 CScriptManager::IntExecuteIntInt(const char* FuncName, s32 p1, s32 p2)
{
	if(m_IntFunctionsIntInt.find(FuncName) != m_IntFunctionsIntInt.end())
	{
		return m_IntFunctionsIntInt[FuncName](p1, p2);
	}
	return -1;
}

// Void, Float methods
void CScriptManager::AddVoidFunctionFloat(const char* FuncName, VoidExecuteFloat_Ptr& Func)
{
	if(m_VoidFunctionsFloat.find(FuncName) == m_VoidFunctionsFloat.end())
	{
		m_VoidFunctionsFloat[FuncName] = Func;
	}
}

void CScriptManager::VoidExecuteFloat(const char* FuncName, const f32& p1)
{
	if(m_VoidFunctionsFloat.find(FuncName) != m_VoidFunctionsFloat.end())
	{
		m_VoidFunctionsFloat[FuncName](p1);
	}
}

// Void, const char*
void CScriptManager::AddVoidFunctionConstChar(const char* FuncName, VoidExecuteConstChar_Ptr& Func)
{
	if(m_VoidFunctionsConstChar.find(FuncName) == m_VoidFunctionsConstChar.end())
	{
		m_VoidFunctionsConstChar[FuncName] = Func;
	}
}

void CScriptManager::VoidExecuteConstChar(const char* FuncName, const char* PlayerName)
{
	if(m_VoidFunctionsConstChar.find(FuncName) != m_VoidFunctionsConstChar.end())
	{
		m_VoidFunctionsConstChar[FuncName](PlayerName);
	}
}

// Void, CGameObject*
void CScriptManager::AddVoidFunctionGameObject(const char* FuncName, VoidExecuteGameObject_Ptr& Func)
{
	if(m_VoidFunctionsGameObject.find(FuncName) == m_VoidFunctionsGameObject.end())
	{
		m_VoidFunctionsGameObject[FuncName] = Func;
	}
}

void CScriptManager::VoidExecuteGameObject(const char* FuncName, CGameObject* GameObject)
{
	if(m_VoidFunctionsGameObject.find(FuncName) != m_VoidFunctionsGameObject.end())
	{
		m_VoidFunctionsGameObject[FuncName](GameObject);
	}
}

#endif