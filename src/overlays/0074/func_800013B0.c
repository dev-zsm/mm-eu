// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0074.h"

void func_80137828(u8 *, u8 *, f32, u8 *);
extern u8 D_6000844;
extern u8 D_80897A58;

void func_800013B0(Actor *thisx) {
    func_80137828((u8 *)thisx + 0x144, &D_6000844, -4.0f, thisx);
    M2C_FIELD(thisx, f32 *, 0x70) = -9.0f;
    M2C_FIELD(thisx, s16 *, 0x32) = M2C_FIELD(thisx, s16 *, 0x92);
    M2C_FIELD(thisx, u8 **, 0x2A8) = &D_80897A58;
}
