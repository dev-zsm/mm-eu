// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B5B20(s32, s32);                        /* extern */
M2C_UNK func_8013E578(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_80A57130;
extern M2C_UNK D_80A58620;

void func_800011D0(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s16 *, 0x452) = 1;
    func_8013E578(arg0 + 0x148, &D_80A58620, 0xE, arg0 + 0x32C);
    M2C_FIELD(arg0, s16 *, 0x116) = 0;
    if (func_800B5B20(arg1, ((s16) M2C_FIELD(arg0, s16 *, 0x1C) >> 7) & 0x7F) != 0) {
        M2C_FIELD(arg0, f32 *, 0x454) = 1.0f;
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80A57130;
}
