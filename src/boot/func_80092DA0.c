// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    s32 pad0;
    s32 unk4;
    s32 unk8;
    u8 pad0C[0x59];
    u8 unk65;
} SomeStruct;

s32 func_80093F40(s32 a0, s32 a1, s32 a2, u8 *a3, s32 sp10);

// best attempt: 5 instr differ (ROM puts `or v0,v1,zero` in the jr delay slot, ours before the epilogue)
s32 func_80092DA0(SomeStruct *pfs, u8 bank) {
    u8 temp[0x20];
    s32 i;
    s32 ret;

    for (i = 0; i < 0x20; i++) {
        temp[i] = bank;
    }
    ret = func_80093F40(pfs->unk4, pfs->unk8, 0x400, temp, 0);
    if (ret == 0) {
        pfs->unk65 = bank;
    }
    return ret;
}
