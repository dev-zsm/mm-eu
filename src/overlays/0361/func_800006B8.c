#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0xC]; f32 unkC; u8 pad10[0xC]; s16 unk1C; u8 pad1E[0xA]; f32 unk28; u8 pad2C[0x134]; f32 unk160; u8 pad164[0xC]; s32 unk170; } S_arg0;

s32 func_800B5B20(s32, s32);                        /* extern */
M2C_UNK func_80A55914(u8 *, s32);                 /* extern */
M2C_UNK func_80A55B3C(u8 *, s32);                 /* extern */
M2C_UNK func_80A55C24(u8 *, s32);                 /* extern */

void func_800006B8(S_arg0 *arg0, s32 arg1) {
    arg0->unk28 = (f32) (arg0->unkC + arg0->unk160);
    func_80A55914(arg0, arg1);
    if (arg0->unk170 & 1) {
        func_80A55B3C(arg0, arg1);
    }
    if (func_800B5B20(arg1, ((s16) arg0->unk1C >> 4) & 0x7F) != 0) {
        func_80A55C24(arg0, arg1);
    }
}
