// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80137828(u8 *, u8 *, f32, u8 *);
extern u8 D_6000844;
extern u8 D_80897A58;

void func_800013B0(u8 *arg0) {
    func_80137828(arg0 + 0x144, &D_6000844, -4.0f, arg0);
    M2C_FIELD(arg0, f32 *, 0x70) = -9.0f;
    M2C_FIELD(arg0, s16 *, 0x32) = M2C_FIELD(arg0, s16 *, 0x92);
    M2C_FIELD(arg0, u8 **, 0x2A8) = &D_80897A58;
}
