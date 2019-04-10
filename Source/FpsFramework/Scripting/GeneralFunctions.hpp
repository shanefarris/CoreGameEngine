#ifdef COMPILE_SCRIPT
#ifndef __GENERALFUNCTIONS_H__
#define __GENERALFUNCTIONS_H__

#include "Defines.h"
#include "CScriptManager.h"

#include "ToLua/lua.h"

namespace Core
{
	class CGameObject;

	void OnStart()
	{
		CScriptManager::ScriptState* state = CScriptManager::Instance()->GetScriptState();
		lua_getglobal(state, START);
		lua_call(state, 0 /* Nubmer of arguments passed in */, 0 /* Number of values passed back */);
	}

	void OnLoadLevel()
	{
		CScriptManager::ScriptState* state = CScriptManager::Instance()->GetScriptState();
		lua_getglobal(state, LOAD_LEVEL);
		lua_call(state, 0, 0);
	}

	void OnUnLoadLevel()
	{
		CScriptManager::ScriptState* state = CScriptManager::Instance()->GetScriptState();
		lua_getglobal(state, UNLOAD_LEVEL);
		lua_call(state, 0, 0);
	}

	void OnPreUpdateGame(const f32& elapsedTime)
	{
		CScriptManager::ScriptState* state = CScriptManager::Instance()->GetScriptState();
		lua_getglobal(state, PRE_UPDATE_GAME);
		lua_pushnumber(state, elapsedTime);
		lua_call(state, 1, 0);
	}

	void OnPostUpdateGame(const f32& elapsedTime)
	{
		CScriptManager::ScriptState* state = CScriptManager::Instance()->GetScriptState();
		lua_getglobal(state, POST_UPDATE_GAME);
		lua_pushnumber(state, elapsedTime);
		lua_call(state, 1, 0);
	}

	void OnPreUpdatePlayers()
	{
		CScriptManager::ScriptState* state = CScriptManager::Instance()->GetScriptState();
		lua_getglobal(state, PRE_UPDATE_PLAYERS);
		lua_call(state, 0, 0);
	}

	void OnPostUpdatePlayers()
	{
		CScriptManager::ScriptState* state = CScriptManager::Instance()->GetScriptState();
		lua_getglobal(state, POST_UPDATE_PLAYERS);
		lua_call(state, 0, 0);
	}

	void OnGameObjectCreate(CGameObject* GameObject)
	{
		CScriptManager::ScriptState* state = CScriptManager::Instance()->GetScriptState();
		lua_getglobal(state, GAMEOBJECT_CREATED);
		lua_pushlightuserdata(state, GameObject);
		lua_call(state, 1, 0);
	}

	void OnGameObjectsPreUpdate()
	{
		CScriptManager::ScriptState* state = CScriptManager::Instance()->GetScriptState();
		lua_getglobal(state, PRE_UPDATE_GAMEOBJECTS);
		lua_call(state, 0, 0);
	}

	void OnGameObjectRemoved(CGameObject* GameObject)
	{
		CScriptManager::ScriptState* state = CScriptManager::Instance()->GetScriptState();
		lua_getglobal(state, GAMEOBJECT_REMOVED);
		lua_pushlightuserdata(state, GameObject);
		lua_call(state, 1, 0);
	}

	void OnPlayerCreate(const char* PlayerName)
	{
		CScriptManager::ScriptState* state = CScriptManager::Instance()->GetScriptState();
		lua_getglobal(state, PLAYER_CREATED);
		lua_pushstring(state, PlayerName);
		lua_call(state, 1, 0);
	}
}

#endif // __GENERALFUNCTIONS_H__

#endif // COMPILE_SCRIPT