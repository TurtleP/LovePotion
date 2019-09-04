#pragma once

int threadNew(lua_State * L);

int threadStart(lua_State * L);

int threadIsRunning(lua_State * L);

int threadWait(lua_State * L);

int threadGetError(lua_State * L);

int threadToString(lua_State * L);

int initLuaThread(lua_State * L);
