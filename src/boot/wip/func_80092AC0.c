// FLAGS: -O2 -g0 -mips2
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
} PiHandle;

extern s32 D_80098310;
extern PiHandle *D_8009807C;
extern PiHandle D_8009E9E0;
extern u8 D_8009E9F4[];

extern void __osPiGetAccess(void);
extern void __osPiRelAccess(void);
extern void bzero(void *p, s32 n);
extern u32 __osDisableInt(void);
extern void __osRestoreInt(u32 a);

PiHandle *osCartRomInit(void) {
    u32 latency;
    u32 pageSize;
    u32 relDuration;
    u32 pulse;
    u32 value;
    u32 prevInt;

    __osPiGetAccess();
    if (D_80098310 == 0) {
        __osPiRelAccess();
        return &D_8009E9E0;
    }
    D_80098310 = 0;
    D_8009E9E0.type = 0;
    D_8009E9E0.baseAddress = 0xB0000000;
    D_8009E9E0.domain = 0;
    D_8009E9E0.speed = 0;
    bzero(D_8009E9F4, 0x60);

    while ((value = *(vu32 *)0xA4600010) & 3) {
    }
    latency = *(vu32 *)0xA4600014;
    pageSize = *(vu32 *)0xA460001C;
    relDuration = *(vu32 *)0xA4600020;
    pulse = *(vu32 *)0xA4600018;
    *(vu32 *)0xA4600014 = 0xFF;
    *(vu32 *)0xA460001C = 0;
    *(vu32 *)0xA4600020 = 3;
    *(vu32 *)0xA4600018 = 0xFF;
    value = *(vu32 *)(D_8009E9E0.baseAddress | 0xA0000000);
    D_8009E9E0.pageSize = (value >> 16) & 0xF;
    D_8009E9E0.relDuration = (value >> 20) & 0xF;
    D_8009E9E0.pulse = value >> 8;
    D_8009E9E0.latency = value;
    *(vu32 *)0xA4600014 = latency;
    *(vu32 *)0xA460001C = pageSize;
    *(vu32 *)0xA4600020 = relDuration;
    *(vu32 *)0xA4600018 = pulse;
    prevInt = __osDisableInt();
    D_8009E9E0.next = D_8009807C;
    D_8009807C = &D_8009E9E0;
    __osRestoreInt(prevInt);
    __osPiRelAccess();
    return &D_8009E9E0;
}
