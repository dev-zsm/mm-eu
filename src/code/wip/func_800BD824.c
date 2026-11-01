// FLAGS: -O2 -g3 -mips2
// STATUS: automatic draft, 24/51 instructions differ
#include "types.h"
#include "m2c_compat.h"

s32 func_800BD724(u8 *);                          /* extern */
M2C_UNK func_8012C78C(u8 *);                      /* extern */
u8 *SkelAnime_DrawFlex(u8 **, s32, s32, u8, s32, s32, s32, u8 *); /* extern */

void func_800BD824(u8 **arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4, s16 arg5) {
    u8 *sp30;
    u8 *temp_a0;
    u8 *temp_v1;
    u8 *temp_v1_2;

    temp_a0 = *arg0;
    func_8012C78C(temp_a0);
    temp_v1 = M2C_FIELD(temp_a0, u8 **, 0x2C0);
    M2C_FIELD(temp_a0, u8 **, 0x2C0) = (u8 *) (temp_v1 + 8);
    M2C_FIELD(temp_v1, s32 *, 0) = 0xFB000000;
    M2C_FIELD(temp_v1, s32 *, 4) = (s32) (arg5 & 0xFF);
    temp_v1_2 = M2C_FIELD(temp_a0, u8 **, 0x2C0);
    M2C_FIELD(temp_a0, u8 **, 0x2C0) = (u8 *) (temp_v1_2 + 8);
    M2C_FIELD(temp_v1_2, s32 *, 0) = 0xDB060030;
    sp30 = temp_v1_2;
    M2C_FIELD(sp30, s32 *, 4) = func_800BD724(*arg0);
    M2C_FIELD(temp_a0, u8 **, 0x2C0) = SkelAnime_DrawFlex(arg0, M2C_FIELD(arg1, s32 *, 4), M2C_FIELD(arg1, s32 *, 0x20), M2C_FIELD(arg1, u8 *, 2), arg2, arg3, arg4, M2C_FIELD(temp_a0, u8 **, 0x2C0));
}
