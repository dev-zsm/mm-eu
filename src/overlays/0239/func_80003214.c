// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0239.h"

void func_80137934(u8 *, u8 *, f32, u8 *);
extern u8 D_6005700;
extern u8 D_809782BC;

void func_80003214(u8 *arg0) {
    func_80137934(arg0 + 0x144, &D_6005700, -4.0f, arg0);
    M2C_FIELD(arg0, f32 *, 0x70) = 6.0f;
    M2C_FIELD(arg0, s16 *, 0x32) = M2C_FIELD(arg0, s16 *, 0xBE);
    M2C_FIELD(arg0, u8 **, 0x290) = &D_809782BC;
}
