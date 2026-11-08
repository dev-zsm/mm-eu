// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_800B6564(u8 *, f32);
extern u8 D_808F1ADC;
extern s16 D_808F24AC;

void func_800012F8(u8 *arg0) {
    M2C_FIELD(arg0, f32 *, 0xC4) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0xCC) = 22.0f;
    M2C_FIELD(arg0, s16 *, 0x270) = D_808F24AC;
    func_800B6564(arg0, 0.0f);
    M2C_FIELD(arg0, u8 **, 0x188) = &D_808F1ADC;
}
