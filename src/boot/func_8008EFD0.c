// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u16 unk0;
    u8 unk2;
    u8 pad3[0x11];
    void *unk14;
} Obj;

extern s32 D_80098060;

s32 func_800920B0(void *a0, Obj *a1, s32 a2);
s32 func_8008FC50(s32 a0, Obj *a1, s32 a2);
s32 func_80087CB0(s32 a0, Obj *a1, s32 a2);

s32 func_8008EFD0(void *a0, Obj *a1, s32 a2) {
    s32 r;

    if (D_80098060 == 0) {
        return -1;
    }
    a1->unk14 = a0;
    if (a2 == 0) {
        a1->unk0 = 0xF;
    } else {
        a1->unk0 = 0x10;
    }
    if (a1->unk2 == 1) {
        r = func_8008FC50(func_800920B0(a0, a1, a2), a1, 0);
    } else {
        r = func_80087CB0(func_800920B0(a0, a1, a2), a1, 0);
    }
    return r;
}
