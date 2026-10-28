// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80830B44(s32, u8 *, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_80834468(u8 *, M2C_UNK *, M2C_UNK, s32); /* extern */
extern M2C_UNK D_400DCD8;
extern M2C_UNK D_80853A90;

void func_80013ADC(s32 arg0, u8 *arg1) {
    func_80834468(arg1, &D_400DCD8, 0x41400000, arg0);
    func_80830B44(arg0, arg1, &D_80853A90, 0);
    M2C_FIELD(arg1, s32 *, 0xA6C) = (s32) (M2C_FIELD(arg1, s32 *, 0xA6C) | 0x20000000);
    M2C_FIELD(arg1, s16 *, 0xB68) = (s16) (s32) M2C_FIELD(arg1, f32 *, 0x28);
}
