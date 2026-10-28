// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[4];
    u8 type;
    u8 latency;
    u8 pageSize;
    u8 relDuration;
    u8 pulse;
    u8 domain;
    u8 padA[2];
    u32 baseAddress;
} PiHandle;

extern PiHandle *D_80098080[];
extern u32 osVirtualToPhysical(void *a0);

// (u32 reads/writes of PI registers use volatile; D_80098080 is the table of current PI handles per domain)
s32 __osEPiRawStartDma(PiHandle *pihandle, s32 dir, u32 cartAddr, void *dramAddr, u32 size) {
    u32 stat;
    s32 domain;

    stat = *(volatile u32 *)0xA4600010;
    while (stat & 3) {
        stat = *(volatile u32 *)0xA4600010;
    }
    domain = pihandle->domain;
    if (D_80098080[domain]->type != pihandle->type) {
        PiHandle *cHandle = D_80098080[domain];

        if (domain == 0) {
            if (cHandle->latency != pihandle->latency) {
                *(volatile u32 *)0xA4600014 = pihandle->latency;
            }
            if (cHandle->pageSize != pihandle->pageSize) {
                *(volatile u32 *)0xA460001C = pihandle->pageSize;
            }
            if (cHandle->relDuration != pihandle->relDuration) {
                *(volatile u32 *)0xA4600020 = pihandle->relDuration;
            }
            if (cHandle->pulse != pihandle->pulse) {
                *(volatile u32 *)0xA4600018 = pihandle->pulse;
            }
        } else {
            if (cHandle->latency != pihandle->latency) {
                *(volatile u32 *)0xA4600024 = pihandle->latency;
            }
            if (cHandle->pageSize != pihandle->pageSize) {
                *(volatile u32 *)0xA460002C = pihandle->pageSize;
            }
            if (cHandle->relDuration != pihandle->relDuration) {
                *(volatile u32 *)0xA4600030 = pihandle->relDuration;
            }
            if (cHandle->pulse != pihandle->pulse) {
                *(volatile u32 *)0xA4600028 = pihandle->pulse;
            }
        }
        cHandle->type = pihandle->type;
        cHandle->latency = pihandle->latency;
        cHandle->pageSize = pihandle->pageSize;
        cHandle->relDuration = pihandle->relDuration;
        cHandle->pulse = pihandle->pulse;
    }
    *(volatile u32 *)0xA4600000 = osVirtualToPhysical(dramAddr);
    *(volatile u32 *)0xA4600004 = (pihandle->baseAddress | cartAddr) & 0x1FFFFFFF;
    switch (dir) {
        case 0:
            *(volatile u32 *)0xA460000C = size - 1;
            break;
        case 1:
            *(volatile u32 *)0xA4600008 = size - 1;
            break;
        default:
            return -1;
    }
    return 0;
}
