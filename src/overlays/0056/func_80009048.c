// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80830B44();
void func_800B8BDC();
extern u8 D_808572DC;

void func_80009048(s32 arg0, u8 *arg1) {
    func_80830B44(arg0, arg1, &D_808572DC, 0);
    M2C_FIELD(arg1, s16 *, 0xB28) = 0;
    M2C_FIELD(arg1, s16 *, 0xB88) = 0;
    M2C_FIELD(arg1, f32 *, 0xAF0) = 0.0f;
    M2C_FIELD(arg1, f32 *, 0xAF4) = 0.0f;
    M2C_FIELD(arg1, f32 *, 0xAF8) = 0.0f;
    M2C_FIELD(arg1, f32 *, 0xB08) = 0.0f;
    M2C_FIELD(arg1, f32 *, 0xB0C) = 0.0f;
    func_800B8BDC(arg1, 0x8E6);
}
