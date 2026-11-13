// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0111.h"

f32 func_800FEB84(s16);                             /* extern */
M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80137070(u8 *);                      /* extern */
M2C_UNK func_808D4A90(u8 *, s32);                 /* extern */
extern f32 D_808D6860;

void func_800020F8(u8 *arg0, s32 arg1) {
    s16 temp_v0;

    func_800FFCBC(arg0 + 0x32, (s16) (M2C_FIELD(arg0, s16 *, 0x92) + 0x8000), 5, 0xDAC, 0xC8);
    temp_v0 = M2C_FIELD(arg0, s16 *, 0x3D4);
    M2C_FIELD(arg0, s16 *, 0xBE) = (s16) M2C_FIELD(arg0, s16 *, 0x32);
    if (temp_v0 >= 0x3D) {
        func_808D4A90(arg0, arg1);
        M2C_FIELD(arg0, s16 *, 0x3D4) = 0;
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x3D8) = (s16) (s32) ((D_808D6860 * ((f32) (0x3C - M2C_FIELD(arg0, s16 *, 0x3D4)) / 60.0f)) * func_800FEB84((s16) (temp_v0 * 0xFA0)));
    func_80137070(arg0 + 0x144);
    M2C_FIELD(arg0, s16 *, 0x3D4) = (s16) (M2C_FIELD(arg0, s16 *, 0x3D4) + 1);
}
