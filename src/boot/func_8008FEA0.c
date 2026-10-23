// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct PiHandle {
    u8 pad0[4];
    u8 latency;
    u8 pageSize;
    u8 relDuration;
    u8 pulse;
    u8 unk8;
    u8 domain;
    u8 padA[2];
    u32 baseAddress;
} PiHandle;

extern PiHandle *D_80098080[];

s32 __osEPiRawReadIo(PiHandle *pihandle, u32 devAddr, u32 *data) {
    register u32 stat;
    u32 domain;

    stat = *(volatile u32 *)0xA4600010;
    while (stat & 3) {
        stat = *(volatile u32 *)0xA4600010;
    }
    domain = pihandle->domain;
    if (D_80098080[domain]->latency != pihandle->latency) {
        PiHandle *cHandle = D_80098080[domain];
        if (domain == 0) {
            if (cHandle->pageSize != pihandle->pageSize) {
                *(u32 *)0xA4600014 = pihandle->pageSize;
            }
            if (cHandle->relDuration != pihandle->relDuration) {
                *(u32 *)0xA460001C = pihandle->relDuration;
            }
            if (cHandle->pulse != pihandle->pulse) {
                *(u32 *)0xA4600020 = pihandle->pulse;
            }
            if (cHandle->unk8 != pihandle->unk8) {
                *(u32 *)0xA4600018 = pihandle->unk8;
            }
        } else {
            if (cHandle->pageSize != pihandle->pageSize) {
                *(u32 *)0xA4600024 = pihandle->pageSize;
            }
            if (cHandle->relDuration != pihandle->relDuration) {
                *(u32 *)0xA460002C = pihandle->relDuration;
            }
            if (cHandle->pulse != pihandle->pulse) {
                *(u32 *)0xA4600030 = pihandle->pulse;
            }
            if (cHandle->unk8 != pihandle->unk8) {
                *(u32 *)0xA4600028 = pihandle->unk8;
            }
        }
        cHandle->latency = pihandle->latency;
        cHandle->pageSize = pihandle->pageSize;
        cHandle->relDuration = pihandle->relDuration;
        cHandle->pulse = pihandle->pulse;
        cHandle->unk8 = pihandle->unk8;
    }
    *data = *(u32 *)((pihandle->baseAddress | devAddr) | 0xA0000000);
    return 0;
}
