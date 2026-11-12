#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x2DC]; s32 unk2DC; u8 pad2E0[0xF2]; s16 unk3D2; u8 pad3D4[0x4]; s16 unk3D8; } S_arg4;

M2C_UNK func_800BBA70();   /* extern */
M2C_UNK func_800E7D4C();                    /* extern */
M2C_UNK func_80182B28();           /* extern */
M2C_UNK func_80182BE0();                      /* extern */
extern M2C_UNK D_8097C2A4;

void func_80002920(s32 arg0, s32 arg1, s32 arg2, M2C_UNK arg3, S_arg4 *arg4) {
    s16 temp_v0;
    s32 temp_v1;

    func_800E7D4C(arg1, (u8 *)arg4 + 0x188);
    temp_v0 = arg4->unk3D8;
    temp_v1 = temp_v0 & 1;
    if ((temp_v1 != 0) && !(temp_v0 & 2)) {
        if (arg1 == 0xB) {
            func_800BBA70(arg4, arg0, 1, arg2);
            arg4->unk3D8 = (s16) (arg4->unk3D8 | 2);
        }
    } else if ((temp_v0 & 0x40) && !(temp_v0 & 0x80) && ((arg1 != 0xB) || (temp_v1 == 0)) && (arg1 != 0xC)) {
        func_800BBA70(arg4, arg0, 1, arg2);
    }
    if (arg4->unk3D2 != 0) {
        if ((arg1 == 2) || (arg1 == 4) || (arg1 == 5) || (arg1 == 6) || (arg1 == 7) || (arg1 == 8) || (arg1 == 9) || (arg1 == 0xD) || (arg1 == 0xE) || (arg1 == 0xF) || (arg1 == 0x10) || (arg1 == 0x11) || (arg1 == 0x12)) {
            func_80182BE0((u8 *)arg4 + (arg4->unk2DC * 0xC) + 0x234);
            arg4->unk2DC = (s32) (arg4->unk2DC + 1);
            return;
        }
        if ((arg1 == 0xB) && !(arg4->unk3D8 & 2)) {
            func_80182B28(&D_8097C2A4, (u8 *)arg4 + (arg4->unk2DC * 0xC) + 0x234);
            arg4->unk2DC = (s32) (arg4->unk2DC + 1);
        }
    }
}
