#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0631.h"
extern u8 D_80BF1224[];
void func_80BF0030(u8 *a, s32 b);

void func_800011A0(u8 *a) {
    M2C_FIELD(a, s32 *, 0x2A4) = 0;
    if (M2C_FIELD(a, s32 *, 0x2D8) != 1) {
        func_80BF0030(a, 1);
    }
    M2C_FIELD(a, s16 *, 0x294) = 0x46;
    M2C_FIELD(a, s16 *, 0x2B4) = 2;
    M2C_FIELD(a, void **, 0x284) = D_80BF1224;
}
