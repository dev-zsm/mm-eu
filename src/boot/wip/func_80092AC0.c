// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
// matching: the function owns its static flag, so the object carries its own .data
// best attempt: 3 sb stores of the config decode are ordered pulse, pageSize, relDuration (ROM: pageSize, relDuration, pulse)
#include "types.h"

typedef volatile u32 vu32;
typedef struct PiHandle {
    struct PiHandle *next;
    u8 type;
    u8 latency;
    u8 pageSize;
    u8 relDuration;
    u8 pulse;
    u8 domain;
    u32 baseAddress;
    u32 speed;
    u8 transferInfo[0x60];
} PiHandle;

extern PiHandle *D_8009807C;
extern PiHandle D_8009E9E0;

void __osPiGetAccess(void);
void __osPiRelAccess(void);
void bzero(void *p, u32 n);
s32 __osDisableInt(void);
void __osRestoreInt(s32 a);

PiHandle *osCartRomInit(void) {
    static s32 sNeedsInit = 1;
    register u32 initialConfig;
    register s32 status;
    register u32 prevInt;
    register u32 lastLatency;
    register u32 lastPageSize;
    register u32 lastRelDuration;
    register u32 lastPulse;

    __osPiGetAccess();
    if (!sNeedsInit) {
        __osPiRelAccess();
        return &D_8009E9E0;
    }
    sNeedsInit = 0;
    D_8009E9E0.type = 0;
    D_8009E9E0.baseAddress = 0xB0000000;
    D_8009E9E0.domain = 0;
    D_8009E9E0.speed = 0;
    bzero(&D_8009E9E0.transferInfo, 0x60);

    status = *(vu32 *)0xA4600010;
    while (status & 3) {
        status = *(vu32 *)0xA4600010;
    }
    lastLatency = *(vu32 *)0xA4600014;
    lastPageSize = *(vu32 *)0xA460001C;
    lastRelDuration = *(vu32 *)0xA4600020;
    lastPulse = *(vu32 *)0xA4600018;
    *(vu32 *)0xA4600014 = 0xFF;
    *(vu32 *)0xA460001C = 0;
    *(vu32 *)0xA4600020 = 3;
    *(vu32 *)0xA4600018 = 0xFF;
    initialConfig = *(vu32 *)(D_8009E9E0.baseAddress | 0xA0000000);
    D_8009E9E0.latency = initialConfig;
    D_8009E9E0.pulse = initialConfig >> 8;
    D_8009E9E0.pageSize = (initialConfig >> 16) & 0xF;
    D_8009E9E0.relDuration = (initialConfig >> 20) & 0xF;
    *(vu32 *)0xA4600014 = lastLatency;
    *(vu32 *)0xA460001C = lastPageSize;
    *(vu32 *)0xA4600020 = lastRelDuration;
    *(vu32 *)0xA4600018 = lastPulse;
    prevInt = __osDisableInt();
    D_8009E9E0.next = D_8009807C;
    D_8009807C = &D_8009E9E0;
    __osRestoreInt(prevInt);
    __osPiRelAccess();
    return &D_8009E9E0;
}
