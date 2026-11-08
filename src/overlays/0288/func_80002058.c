// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0288.h"

void func_80137934(u8 *, u8 *, f32, u8 *);
extern u8 D_6000A5C;
extern u8 D_809D52C0;

void func_80002058(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, u8 **, 0x170) = &D_809D52C0;
    func_80137934(arg0 + 0x3C8, &D_6000A5C, 0.0f, arg0);
    M2C_FIELD(arg0, s16 *, 0x162) = 0x3C;
    M2C_FIELD(arg0, f32 *, 0x358) = 0.0f;
}
