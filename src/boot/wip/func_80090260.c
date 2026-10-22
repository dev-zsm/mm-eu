// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[4];
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    u8 unk8;
    u8 unk9;
    u8 padA[2];
    u32 unkC;
} PiHandle;

extern PiHandle *D_80098080[];
extern u32 osVirtualToPhysical(void *a0);

s32 __osEPiRawStartDma(PiHandle *arg0, s32 arg1, u32 arg2, void *arg3, u32 arg4) {
    PiHandle *temp_v1;
    u32 temp_v0;
    s32 idx;


    while (*(u32 *)0xA4600010 & 3) {}

    idx = arg0->unk9;
    temp_v1 = D_80098080[idx];
    if (arg0->unk4 != temp_v1->unk4) {
        if (idx != 0) {
            if (arg0->unk5 != temp_v1->unk5) {
                *(u32 *)0xA4600014 = arg0->unk5;
            }
            if (arg0->unk6 != temp_v1->unk6) {
                *(u32 *)0xA460001C = arg0->unk6;
            }
            if (arg0->unk7 != temp_v1->unk7) {
                *(u32 *)0xA4600020 = arg0->unk7;
            }
            if (arg0->unk8 != temp_v1->unk8) {
                *(u32 *)0xA4600018 = arg0->unk8;
            }
        } else {
            if (arg0->unk5 != temp_v1->unk5) {
                *(u32 *)0xA4600024 = arg0->unk5;
            }
            if (arg0->unk6 != temp_v1->unk6) {
                *(u32 *)0xA460002C = arg0->unk6;
            }
            if (arg0->unk7 != temp_v1->unk7) {
                *(u32 *)0xA4600030 = arg0->unk7;
            }
            if (arg0->unk8 != temp_v1->unk8) {
                *(u32 *)0xA4600028 = arg0->unk8;
            }
        }
        temp_v1->unk4 = arg0->unk4;
        temp_v1->unk5 = arg0->unk5;
        temp_v1->unk6 = arg0->unk6;
        temp_v1->unk7 = arg0->unk7;
        temp_v1->unk8 = arg0->unk8;
    }

    temp_v0 = osVirtualToPhysical(arg3);
    *(u32 *)0xA4600000 = temp_v0;
    *(u32 *)0xA4600004 = (arg0->unkC | arg2) & 0x1FFFFFFF;

    if (arg1 == 0) {
        *(u32 *)0xA460000C = arg4 - 1;
        return 0;
    }
    if (arg1 == 1) {
        *(u32 *)0xA4600008 = arg4 - 1;
        return 0;
    }
    return -1;
}
