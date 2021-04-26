#pragma once

#include "common/module.h"
#include "common/stringmap.h"

using namespace std::literals::string_literals;

#define OS_NAME "Horizon"

#if defined(_3DS)
    #define LANGUAGE_COUNT 12
#elif defined(__SWITCH__)
    #define LANGUAGE_COUNT 17
#endif

namespace love::common
{
    class System : public Module
    {
      public:
        enum PowerState
        {
            POWER_UNKNOWN,
            POWER_BATTERY,
            POWER_CHARGING,
            POWER_CHARGED,
            POWER_MAX_ENUM
        };

        enum NetworkState
        {
            NETWORK_UNKNOWN,
            NETWORK_DISCONNECTED,
            NETWORK_CONNECTED,
            NETWORK_MAX_ENUM
        };

        enum SystemTheme
        {
            THEME_LIGHT,
            THEME_DARK,
            THEME_MAX_ENUM
        };

        struct PowerInfo
        {
            std::string state;
            int percentage;
        };

        struct NetworkInfo
        {
            std::string status;
            int signal;
        };

        System();

        ModuleType GetModuleType() const
        {
            return M_SYSTEM;
        }

        const char* GetName() const override
        {
            return "love.system";
        }

        /* LÖVE2D Functions */

        std::string GetOS() const;

        /* pure virtual subclass stuff */

        virtual int GetProcessorCount() = 0;

        virtual PowerInfo GetPowerInfo() const = 0;

        virtual const std::string& GetUsername() = 0;

        virtual NetworkInfo GetNetworkInfo() const = 0;

        virtual const std::string& GetSystemTheme() = 0;

        virtual const std::string& GetLanguage() = 0;

        virtual const std::string& GetVersion() = 0;

        virtual const std::string& GetRegion() = 0;

        virtual const std::string& GetModel() = 0;

        virtual const std::string& GetFriendCode() = 0;

        /* end pure virtual methods */

        PowerState GetPowerInfo(int& percent) const;

        NetworkState GetNetworkInfo(int& signal) const;

        static bool GetConstant(const char* in, PowerState& out);
        static bool GetConstant(PowerState in, const char*& out);

        static bool GetConstant(const char* in, NetworkState& out);
        static bool GetConstant(NetworkState in, const char*& out);

      protected:
        struct
        {
            int processors;
            std::string model;
            std::string region;
            std::string version;
            std::string username;
            std::string language;
            std::string friendCode;
            std::string colorTheme;
        } systemInfo;

      private:
        const static StringMap<PowerState, POWER_MAX_ENUM> powerStates;
        const static StringMap<NetworkState, NETWORK_MAX_ENUM> networkStates;
    };
} // namespace love::common
