// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0265.h"

void func_809936F0();
extern s32 D_80995C80;

void func_80001420(u8 *arg0) {
    f32 x = M2C_FIELD(arg0, f32 *, 0x15C);

    if (x >= M2C_FIELD(arg0, f32 *, 0x350)) {
        M2C_FIELD(arg0, s16 *, 0x28A) = 0;
        if (M2C_FIELD(arg0, s16 *, 0x28E) != 0) {
            M2C_FIELD(arg0, s16 *, 0x28E) = 0;
            D_80995C80 = 0;
        }
        func_809936F0();
    }
}
