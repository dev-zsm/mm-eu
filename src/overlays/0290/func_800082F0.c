// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0290.h"

void func_80137934(u8 *, u8 *, f32, u8 *);
extern u8 D_6002D84;
extern u8 D_809E19FC;

void func_800082F0(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, u8 **, 0x144) = &D_809E19FC;
    func_80137934(arg0 + 0x190, &D_6002D84, 0.0f, arg0);
    M2C_FIELD(arg0, s32 *, 4) &= ~1;
    M2C_FIELD(arg0, s16 *, 0x17D8) = 0x6E00;
}
