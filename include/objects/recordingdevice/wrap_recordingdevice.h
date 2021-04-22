#include "common/luax.h"
#include "objects/recordingdevice/recordingdevice.h"

namespace Wrap_RecordingDevice
{
    int Start(lua_State* L);

    int Stop(lua_State* L);

    int GetData(lua_State* L);

    int GetSampleCount(lua_State* L);

    int GetSampleRate(lua_State* L);

    int GetBitDepth(lua_State* L);

    int GetChannelCount(lua_State* L);

    int GetName(lua_State* L);

    int IsRecording(lua_State* L);

    // RecordingDevice* CheckRecordingDevice(lua_State* L, int index);

    int Register(lua_State* L);
} // namespace Wrap_RecordingDevice
