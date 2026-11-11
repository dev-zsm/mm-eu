// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0228.h"

void func_800B8C4C();
extern u8 D_809692E4;
extern u8 D_80969704;

void func_80001074(u8 *arg0) {
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    if (&D_809692E4 == M2C_FIELD(arg0, u8 **, 0x144)) {
        M2C_FIELD(arg0, s16 *, 0x14A) = 1;
    } else {
        M2C_FIELD(arg0, s16 *, 0x14A) = 4;
    }
    func_800B8C4C(arg0, 0x38D9);
    M2C_FIELD(arg0, u8 **, 0x144) = &D_80969704;
}
