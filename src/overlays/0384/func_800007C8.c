// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800EDFA0(s32, M2C_UNK, u8 *);            /* extern */
s32 func_800EE03C(s32, M2C_UNK, u8 *);            /* extern */

void func_800007C8(u8 *arg0, s32 arg1) {
    s32 temp_t8;
    u8 *temp_v1;

    if (func_800EE03C(arg1, 0x1D9, arg0) != 0) {
        temp_t8 = func_800EDFA0(arg1, 0x1D9, arg0) * 4;
        M2C_FIELD(arg0, s8 *, 0x18E) = 1;
        temp_v1 = arg1 + temp_t8;
        M2C_FIELD(arg0, f32 *, 0x190) = (f32) M2C_FIELD(M2C_FIELD(temp_v1, u8 **, 0x1F4C), s32 *, 0xC);
        M2C_FIELD(arg0, f32 *, 0x194) = (f32) M2C_FIELD(M2C_FIELD(temp_v1, u8 **, 0x1F4C), s32 *, 0x10);
        M2C_FIELD(arg0, f32 *, 0x198) = (f32) M2C_FIELD(M2C_FIELD(temp_v1, u8 **, 0x1F4C), s32 *, 0x14);
    }
}
