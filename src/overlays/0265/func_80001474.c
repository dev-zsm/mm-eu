// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80992908();
extern u8 D_80993AEC;

void func_80001474(u8 *arg0) {
    func_80992908(arg0, 4);
    M2C_FIELD(arg0, s16 *, 0x32) = -M2C_FIELD(arg0, s16 *, 0x92);
    M2C_FIELD(arg0, u8 **, 0x278) = &D_80993AEC;
    M2C_FIELD(arg0, f32 *, 0x70) = 10.0f;
    M2C_FIELD(arg0, f32 *, 0x68) = 20.0f;
}
