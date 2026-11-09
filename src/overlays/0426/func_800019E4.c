#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x2D8]; void *unk2D8; u8 pad2DC[0x5C]; u16 unk338; u8 pad33A[0x2]; s16 unk33C; u8 pad33E[0x28]; s16 unk366; } S_arg0;
typedef struct { u8 pad0[0x1682E]; s8 unk1682E; u8 pad1682F[0x100]; s8 unk1692F; } S_arg1;

M2C_UNK func_800F1944(s16);                         /* extern */
s32 func_800F1984(s16);                             /* extern */
M2C_UNK func_800F1A08(s16, u8 *);                 /* extern */
M2C_UNK func_800F1D6C(s16);                         /* extern */
s32 func_800F1E2C();                                /* extern */
s16 func_800F1E68(s16);                             /* extern */
s32 func_80147B34(u8 *);                          /* extern */
s32 func_801529DC(s32);                             /* extern */
extern M2C_UNK D_80AC15F4;

void func_800019E4(S_arg0 *arg0, S_arg1 *arg1) {
    s16 temp_v1;
    s32 temp_v0;

    temp_v0 = func_801529DC((u8 *)arg1 + 0x4908);
    temp_v1 = arg0->unk366;
    if (temp_v1 == 0) {
        if (func_800F1984(arg0->unk33C) != 0) {
            func_800F1A08(arg0->unk33C, arg0);
            arg0->unk366 = 1;
            return;
        }
        if (func_800F1E2C() == 0x7C) {
            func_800F1D6C(0x7C);
        }
        func_800F1944(arg0->unk33C);
        return;
    }
    if ((temp_v1 == 1) && (temp_v0 == 5) && (func_80147B34(arg1) != 0)) {
        arg1->unk1682E = 0x43;
        arg1->unk1692F = 4;
        arg0->unk366 = 0;
        func_800F1D6C(arg0->unk33C);
        arg0->unk33C = func_800F1E68(arg0->unk33C);
        func_800F1944(arg0->unk33C);
        arg0->unk338 = (u16) (arg0->unk338 | 8);
        arg0->unk2D8 = &D_80AC15F4;
    }
}
