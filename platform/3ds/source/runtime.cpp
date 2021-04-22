#include <3ds.h>
#include <malloc.h>

#include "common/results.h"

u32* SOCKET_BUFFER;
u8* MICROPHONE_BUFFER;

#define SOC_BUFSIZE 0x100000
#define MIC_BUFSIZE 0x30000

#define BUFFER_ALIGN 0x1000

extern "C" {
void userAppInit()
{
    osSetSpeedupEnable(true);

    /* microphone */
    MICROPHONE_BUFFER = (u8*)memalign(BUFFER_ALIGN, MIC_BUFSIZE);
    micInit(MICROPHONE_BUFFER, MIC_BUFSIZE);

    /* mcu:hwc for raw battery info */
    R_ABORT_UNLESS(mcuHwcInit());

    /* battery state */
    R_ABORT_UNLESS(ptmuInit());

    /* wifi state */
    R_ABORT_UNLESS(acInit());

    /* friends */
    R_ABORT_UNLESS(frdInit());

    /* wireless */
    SOCKET_BUFFER = (u32*)memalign(BUFFER_ALIGN, SOC_BUFSIZE);
    socInit(SOCKET_BUFFER, SOC_BUFSIZE);

    HIDUSER_EnableAccelerometer();

    /* so we can have preemptive threads */
    APT_SetAppCpuTimeLimit(30);
}

void userAppExit()
{
    HIDUSER_DisableAccelerometer();

    socExit();
    free(SOCKET_BUFFER);

    frdExit();

    acExit();

    ptmuExit();

    mcuHwcExit();

    micExit();
    free(MICROPHONE_BUFFER);
}
}
