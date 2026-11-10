#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x1682E]; s8 unk1682E; u8 pad1682F[0x100]; s8 unk1692F; } S_arg1;
typedef struct { u8 pad0[0x92]; s16 unk92; u8 pad94[0xB4]; void *unk148; u8 pad14C[0x98]; u16 unk1E4; u8 pad1E6[0x210]; s16 unk3F6; } S_arg0;

M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
s32 func_80147B34(u8 *);                          /* extern */
s32 func_801529DC(s32);                             /* extern */
extern M2C_UNK D_80B91DA4;
extern M2C_UNK D_80B92398;
extern M2C_UNK D_80B92598;
extern M2C_UNK D_80B92CDC;

void func_80002A60(S_arg0 *arg0, S_arg1 *arg1) {
    s32 temp_v0;
    u16 temp_v0_2;

    temp_v0 = func_801529DC((u8 *)arg1 + 0x4908);
    if (((temp_v0 == 5) || (temp_v0 == 6)) && (func_80147B34(arg1) != 0)) {
        arg1->unk1682E = 0x43;
        arg1->unk1692F = 4;
        temp_v0_2 = arg0->unk1E4;
        if (temp_v0_2 & 8) {
            arg0->unk148 = &D_80B91DA4;
        } else if (temp_v0_2 & 4) {
            arg0->unk148 = &D_80B92598;
        } else if (temp_v0_2 & 2) {
            arg0->unk148 = &D_80B92398;
        } else if (temp_v0_2 & 1) {
            arg0->unk3F6 = 0x14;
            arg0->unk148 = &D_80B92CDC;
        }
    }
    func_800FFCBC((u8 *)arg0 + 0xBE, arg0->unk92, 5, 0x1000, 0x100);
}
