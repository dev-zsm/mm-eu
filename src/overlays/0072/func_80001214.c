// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80890A40();
extern u8 D_808919F0;

void func_80001214(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s16 *, 0x256) = 0x64;
    if (M2C_FIELD(arg0, s16 *, 0x252) == 0) {
        M2C_FIELD(arg0, s16 *, 0x252) = 0x3C;
        M2C_FIELD(arg0, s16 *, 0x24C) = 0xA;
        M2C_FIELD(arg0, s16 *, 0x29C) = 4;
        M2C_FIELD(arg0, s16 *, 0x28E) = 2;
        M2C_FIELD(arg0, u8 **, 0x248) = &D_808919F0;
    }
    func_80890A40(arg0, arg1, M2C_FIELD(arg0, s16 *, 0x29C));
}
