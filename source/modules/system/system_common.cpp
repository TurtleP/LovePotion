#include "common/runtime.h"
#include "modules/system/system.h"

using namespace love;

System::System() : sysInfo()
{ /* initialize sysInfo defaults */ }

std::string System::GetOS() const
{
    return OS_NAME;
}

System::PowerState System::GetPowerInfo(int & percent) const
{
    PowerState state = POWER_UNKNOWN;

    PowerInfo info = this->GetPowerInfo();

    this->GetConstant(info.state.c_str(), state);
    percent = info.percentage;

    return state;
}

System::NetworkState System::GetNetworkInfo(int & signal) const
{
    NetworkState state = NETWORK_UNKNOWN;

    NetworkInfo info = this->GetNetworkInfo();

    this->GetConstant(info.status.c_str(), state);
    signal = info.signal;

    return state;
}

bool System::GetConstant(const char * in, System::PowerState & out)
{
	return powerStates.Find(in, out);
}

bool System::GetConstant(System::PowerState in, const char *& out)
{
	return powerStates.Find(in, out);
}

bool System::GetConstant(const char * in, System::NetworkState & out)
{
	return networkStates.Find(in, out);
}

bool System::GetConstant(System::NetworkState in, const char *& out)
{
	return networkStates.Find(in, out);
}

StringMap<System::PowerState, System::POWER_MAX_ENUM>::Entry System::powerEntries[] =
{
    { "unknown",  System::POWER_UNKNOWN   },
    { "battery",  System::POWER_BATTERY   },
    { "charging", System::POWER_CHARGING  },
    { "charged",  System::POWER_CHARGED   }
};

StringMap<System::PowerState, System::POWER_MAX_ENUM> System::powerStates(System::powerEntries, sizeof(System::powerEntries));

StringMap<System::NetworkState, System::NETWORK_MAX_ENUM>::Entry System::networkEntries[] =
{
    { "unknown",      System::NETWORK_UNKNOWN      },
    { "disconnected", System::NETWORK_DISCONNECTED },
    { "connected",    System::NETWORK_CONNECTED    },
};

StringMap<System::NetworkState, System::NETWORK_MAX_ENUM> System::networkStates(System::networkEntries, sizeof(System::networkEntries));
