// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x16];
    s16 unk16;
    u8 pad18[0xBE - 0x18];
    s16 unkBE;
    u8 padC0[0xA74 - 0xC0];
    u32 unkA74;
    u8 padA78[0xAD4 - 0xA78];
    s16 unkAD4;
    u8 padAD6[0xB08 - 0xAD6];
    f32 unkB08;
    f32 unkB0C;
    u8 padB10[0xB8C - 0xB10];
    s16 unkB8C;
    u8 padB8E[0xD5C - 0xB8E];
    u8 unkD5C;
} Obj;

typedef struct {
    u8 pad0[0x1CCC];
    Obj *unk1CCC;
} Ctx;

extern f32 D_801D5DB8;

s32 func_80123A8C(Ctx *arg0, f32 arg1, s16 arg2) {
    Obj *temp_v1;

    temp_v1 = arg0->unk1CCC;
    if (temp_v1->unkA74 & 0x1000) {
        temp_v1->unkB08 = arg1;
        temp_v1->unkB0C = temp_v1->unkB0C + (arg1 * D_801D5DB8);
        temp_v1->unkAD4 = arg2;
        temp_v1->unk16 = arg2;
        temp_v1->unkBE = arg2;
        temp_v1->unkB8C = 4;
        temp_v1->unkD5C = 0x14;
        return 1;
    }
    return 0;
}
