// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80137828(u8 *, u8 *, f32, u8 *);
extern u8 D_6001040;
extern u8 D_8089C194;

void func_80002334(u8 *arg0) {
    func_80137828(arg0 + 0x144, &D_6001040, -5.0f, arg0);
    M2C_FIELD(arg0, u8 *, 0x375) |= 1;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    M2C_FIELD(arg0, s16 *, 0x32) = M2C_FIELD(arg0, s16 *, 0xBE);
    M2C_FIELD(arg0, u8 **, 0x284) = &D_8089C194;
}
