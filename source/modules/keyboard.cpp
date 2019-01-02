#include "common/runtime.h"
#include "modules/keyboard.h"

int Keyboard::ShowTextInput(lua_State * L)
{
    SwkbdConfig keyboard;
    char text[0x20] = {0};

    if (!lua_istable(L, 1) || !lua_isnoneornil(L, 1))
        luaL_error(L, "table expected, got %s", lua_type(L, 1));
    else if (lua_istable(L, 1))
        lua_settop(L, 1);
    else if (lua_isnoneornil(L, 1))
        lua_newtable(L);

    /*
    {
        [“type”] = “QWERTY”,
        [“header”] = “Enter Text”,
        [“subheader”] = “”,
        [“hint”] = “Some Text”,
        [“isPassword”] = false
    }
    */

    lua_getfield(L, 1, "type");
    lua_getfield(L, 1, "header");
    lua_getfield(L, 1, "subheader");
    lua_getfield(L, 1, "hint");
    lua_getfield(L, 1, "isPassword");

    string type = luaL_optstring(L, -5, "QWERTY");
    
    const char * header = luaL_optstring(L, -4, "Enter Text");
    const char * subHeader = luaL_optstring(L, -3, "");
    const char * hint = luaL_optstring(L, -2, "");

    bool isPassword = lua_toboolean(L, -1);

    swkbdCreate(&keyboard, 0);

    SwkbdArgV0 args = keyboard.arg.arg;

    if (type == "QWERTY")
        args.type = SwkbdType_QWERTY;
    else if (type == "NumPad")
        args.type = SwkbdType_NumPad;

    args.initialCursorPos = 1;
    args.returnButtonFlag = 1;
    
    args.blurBackground = 1;
    
    args.textDrawType = SwkbdTextDrawType_Line;

    args.passwordFlag = isPassword;

    swkbdConfigSetOkButtonText(&keyboard, "OK");

    swkbdConfigSetHeaderText(&keyboard, header);
    swkbdConfigSetSubText(&keyboard, subHeader);

    swkbdConfigSetGuideText(&keyboard, hint);

    swkbdShow(&keyboard, text, sizeof(text));

    love_getfield(L, "textinput");
    if (!lua_isnil(L, -1))
    {
        lua_pushstring(L, text);
        lua_call(L, 1, 0);
    }

    swkbdClose(&keyboard);

    return 0;
}

int Keyboard::Register(lua_State * L)
{
    luaL_Reg reg[] = 
    {
        { "showTextInput", ShowTextInput },
        { 0, 0 },
    };

    luaL_newlib(L, reg);
    
    return 1;
}