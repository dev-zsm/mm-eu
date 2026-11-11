#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0056.h"

s32 func_80123960(u8 *);                          /* extern */
s32 func_80134AE8(s32);                             /* extern */
M2C_UNK func_801367B4(u8 *, u8 *, s32, M2C_UNK, f32, f32, s32, f32); /* extern */
s32 func_8082F298(u8 *);                          /* extern */
s32 func_80830108(u8 *, u8 *);                  /* extern */
M2C_UNK func_80830198(u8 *);                      /* extern */
extern u16 *D_80862264;

s32 func_800030F8(u8 *arg0, u8 *arg1) {
    s32 sp34;
    f32 temp_f0;
    s32 temp_v0;
    s32 temp_v0_3;
    s32 temp_v0_2;

    if (~(*D_80862264 | ~0x10) == 0) {
        temp_v0 = M2C_FIELD(arg1, s32 *, 0xA6C);
        if (!(temp_v0 & 0x20C00000) && (!(temp_v0 & 0x08000000) || ((M2C_FIELD(arg1, s8 *, 0x145) >= 5) && (M2C_FIELD(arg1, u16 *, 0x90) & 1))) && (M2C_FIELD(arg0, s8 *, 0x1887C) == 0) && (M2C_FIELD(arg1, s8 *, 0x14A) == M2C_FIELD(arg1, s8 *, 0x147)) && ((M2C_FIELD(arg1, u8 *, 0x14B) == 0) || ((func_80123960(arg1) == 0) && (((temp_v0_2 = M2C_FIELD(arg1, u8 *, 0x14B), (temp_v0_2 == 2)) && !(M2C_FIELD(arg1, s32 *, 0xA6C) & 0x02000000)) || ((temp_v0_2 == 4) && (M2C_FIELD(arg1, s8 *, 0x144) != 0))) && (func_8082F298(arg1) != 0)))) {
            temp_v0_3 = func_80830108(arg0, arg1);
            sp34 = temp_v0_3;
            temp_f0 = (f32) func_80134AE8(temp_v0_3);
            func_801367B4(arg0, arg1 + 0x284, sp34, 0x3F800000, temp_f0, temp_f0, 2, 0.0f);
            func_80830198(arg1);
            return 1;
        }
    }
    return 0;
}
