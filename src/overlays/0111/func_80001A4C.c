// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_801377D0();
extern u8 D_6006EEC;
extern u8 D_808D4F9C;

void func_80001A4C(u8 *arg0) {
    func_801377D0(arg0 + 0x144, &D_6006EEC, arg0);
    M2C_FIELD(arg0, s16 *, 0x3D6) = 0;
    M2C_FIELD(arg0, u8 *, 0x3EB) = 0;
    M2C_FIELD(arg0, u8 *, 0x3EA) = 0xC8;
    M2C_FIELD(arg0, u8 *, 0x3EF) = 0xA;
    M2C_FIELD(arg0, u8 **, 0x188) = &D_808D4F9C;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
}
