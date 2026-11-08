// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0056.h"

void func_80830DDC();
extern u8 D_8084EBDC;

void func_8000A1B8(s32 arg0, u8 *arg1) {
    s32 a = M2C_FIELD(arg1, s16 *, 0xAE8);
    s32 b = M2C_FIELD(arg1, s8 *, 0xAE7);

    func_80830DDC(arg0, arg1, &D_8084EBDC, 0);
    M2C_FIELD(arg1, f32 *, 0x68) = 0.0f;
    M2C_FIELD(arg1, s16 *, 0xAE8) = a;
    M2C_FIELD(arg1, s8 *, 0xAE7) = b;
}
