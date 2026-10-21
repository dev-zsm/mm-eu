// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    u8 pad20[0x18];
    s32 unk38;
    s32 unk3C;
} Thing;

void *func_80088720(void);
void func_8008A780(void *arg0, s32 arg1);
s32 func_8008AE80(s32 arg0, u32 arg1, void *arg2, s32 arg3);
s32 func_8008FBA0(void);
void func_80095420(s32 arg0);
s32 func_800966B0(u32 arg0);

void func_8008882C(Thing *arg0) {
    Thing *temp_v0;
    s32 temp_s0;

    temp_v0 = func_80088720();
    if (temp_v0->unk4 & 1) {
        temp_v0->unk18 = temp_v0->unk38;
        temp_v0->unk1C = temp_v0->unk3C;
        arg0->unk4 &= ~1;
        if (temp_v0->unk4 & 4) {
            temp_v0->unk10 = *(s32 *)((arg0->unk38 + 0xBFC) | 0xA0000000);
        }
    }
    func_8008A780(temp_v0, 0x40);
    func_80095420(0x2B00);
    temp_s0 = 0x04000000;
    if (func_800966B0(0x04001000) == -1) {
        do {
        } while (func_800966B0(0x04001000) == -1);
    }
    temp_s0 |= 0xFC0;
    if (func_8008AE80(1, temp_s0, temp_v0, 0x40) == -1) {
        do {
        } while (func_8008AE80(1, temp_s0, temp_v0, 0x40) == -1);
    }
    if (func_8008FBA0() != 0) {
        do {
        } while (func_8008FBA0() != 0);
    }
    if (func_8008AE80(1, 0x04001000, temp_v0->unk8, temp_v0->unkC) == -1) {
        do {
        } while (func_8008AE80(1, 0x04001000, temp_v0->unk8, temp_v0->unkC) == -1);
    }
}
