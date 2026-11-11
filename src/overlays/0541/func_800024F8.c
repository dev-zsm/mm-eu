#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x28C]; s32 unk28C; u8 pad290[0x166]; s16 unk3F6; } S_arg4;

M2C_UNK func_80182BE0(u8 *, s32, u8 *);              /* extern */

void func_800024F8(s32 arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3, S_arg4 *arg4) {
    if ((arg4->unk3F6 != 0) && ((arg1 == 3) || (arg1 == 4) || (arg1 == 6) || (arg1 == 8) || (arg1 == 9) || (arg1 == 0xB) || (arg1 == 0xE) || (arg1 == 0x10) || (arg1 == 0x11) || (arg1 == 0x12) || (arg1 == 0x14) || (arg1 == 0x15) || (arg1 == 0x16) || (arg1 == 0x18) || (arg1 == 0x19))) {
        func_80182BE0((u8 *)arg4 + (arg4->unk28C * 0xC) + 0x1D8, arg1, arg4);
        arg4->unk28C = (s32) (arg4->unk28C + 1);
    }
}
