// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0240.h"

void func_800BD9E0(u8 *, u8 *, s32, u8 *);
extern u8 D_8097A7CC;
extern u8 D_8097C070;
extern f32 D_8097C2E0;

void func_80001280(u8 *arg0) {
    func_800BD9E0(arg0 + 0x144, &D_8097C070, 0, arg0);
    M2C_FIELD(arg0, f32 *, 0x70) = D_8097C2E0;
    M2C_FIELD(arg0, s16 *, 0x3DA) = 0;
    M2C_FIELD(arg0, s16 *, 0x3DE) = 2;
    M2C_FIELD(arg0, u8 **, 0x228) = &D_8097A7CC;
}
