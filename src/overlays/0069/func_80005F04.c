// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0069.h"

void func_80880DAC();
void func_801A0070();

void func_80005F04(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x200) = 0;
    M2C_FIELD(arg0, s32 *, 0x214) = 0;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    func_80880DAC(arg0, arg1);
    if (M2C_FIELD(arg0, s32 *, 0x1E8) & 0x08000000) {
        func_801A0070(arg0 + 0x218, 0x1844, arg0);
    }
}
