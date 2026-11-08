// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80137934(u8 *, u8 *, f32, u8 *);
extern u8 D_6006294;
extern u8 D_8090EB10;
extern f32 D_80910D18;

void func_800006B8(u8 *arg0) {
    func_80137934(arg0 + 0x144, &D_6006294, -4.0f, arg0);
    M2C_FIELD(arg0, f32 *, 0x70) = D_80910D18;
    M2C_FIELD(arg0, s16 *, 0x32) = M2C_FIELD(arg0, s16 *, 0xBE);
    M2C_FIELD(arg0, u8 **, 0x2F0) = &D_8090EB10;
}
