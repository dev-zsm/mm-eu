#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0xBE]; s16 unkBE; u8 padC0[0x146]; s16 unk206; u8 pad208[0x2]; s16 unk20A; u8 pad20C[0x87]; s8 unk293; } S_arg0;

M2C_UNK func_800FEC70(u8 *, M2C_UNK, M2C_UNK, u8 *); /* extern */
M2C_UNK func_80B47014(u8 *, s32);                 /* extern */

void func_80000BEC(S_arg0 *arg0, s32 arg1) {
    s16 var_v0;

    var_v0 = arg0->unk206;
    if (var_v0 != 0) {
        arg0->unk206 = (s16) (var_v0 - 1);
        var_v0 = arg0->unk206;
    }
    arg0->unkBE = (s16) (arg0->unkBE + arg0->unk20A);
    if (var_v0 < 0x10) {
        func_800FEC70((u8 *)arg0 + 0x20A, 0, 0x200, arg0);
        var_v0 = arg0->unk206;
    }
    arg0->unk293 = (s8) (u32) ((f32) var_v0 * 7.96875f);
    if (var_v0 == 0) {
        arg0->unk293 = 0;
        func_80B47014(arg0, arg1);
    }
}
