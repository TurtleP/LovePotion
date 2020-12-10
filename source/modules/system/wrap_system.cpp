#include "common/runtime.h"
#include "modules/system/wrap_system.h"

using namespace love;

#define instance() (Module::GetInstance<System>(Module::M_SYSTEM))

int Wrap_System::GetOS(lua_State * L)
{
    std::string os = instance()->GetOS();

    Luax::PushString(L, os);

    return 1;
}


int Wrap_System::GetProcessorCount(lua_State * L)
{
    lua_pushinteger(L, instance()->GetProcessorCount());

    return 1;
}

int Wrap_System::GetPowerInfo(lua_State * L)
{
    int percent = -1;
    const char * str;

    System::PowerState state = instance()->GetPowerInfo(percent);

    if (!System::GetConstant(state, str))
        str = "unknown";

    lua_pushstring(L, str);

    if (percent >= 0)
        lua_pushinteger(L, percent);
    else
        lua_pushnil(L);

    /*
    ** time remaining (seconds)
    ** but we can't calculate this
    ** so just return nil
    */

    lua_pushnil(L);

    return 3;
}

int Wrap_System::GetNetworkInfo(lua_State * L)
{
    int signal = -1;
    const char * str;

    System::NetworkState state = instance()->GetNetworkInfo(signal);

    if (!System::GetConstant(state, str))
        str = "unknown";

    lua_pushstring(L, str);
    lua_pushinteger(L, signal);

    return 2;
}

int Wrap_System::GetLanguage(lua_State * L)
{
    std::string language = instance()->GetLanguage();

    Luax::PushString(L, language);

    return 1;
}

int Wrap_System::GetUsername(lua_State * L)
{
    std::string username = instance()->GetUsername();

    Luax::PushString(L, username);

    return 1;
}

int Wrap_System::GetVersion(lua_State * L)
{
    std::string version = instance()->GetVersion();

    Luax::PushString(L, version);

    return 1;
}

int Wrap_System::Register(lua_State * L)
{
    luaL_Reg reg[] =
    {
        { "getOS",             GetOS             },
        { "getProcessorCount", GetProcessorCount },
        { "getPowerInfo",      GetPowerInfo      },
        { "getNetworkInfo",    GetNetworkInfo    },
        { "getLanguage",       GetLanguage       },
        { "getUsername",       GetUsername       },
        { "getVersion",        GetVersion        },
        { 0, 0 }
    };

    System * instance = instance();

    if (instance == nullptr)
        #if defined (_3DS)
            Luax::CatchException(L, [&]() { instance = new ctr::System(); });
        #else
            Luax::CatchException(L, [&]() { instance = new hac::System(); });
        #endif
    else
        instance->Retain();

    WrappedModule module;
    module.instance = instance;
    module.name = "system";
    module.type = &Module::type;
    module.functions = reg;
    module.types = nullptr;

    return Luax::RegisterModule(L, module);
}
