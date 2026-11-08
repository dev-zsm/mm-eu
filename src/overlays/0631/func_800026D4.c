#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0631.h"
extern u8 D_80BF2754[];
void func_80151DF4(u8 *a, s32 b);

void func_800026D4(u8 *a, u8 *play) {
    M2C_FIELD(a, s32 *, 0x2A4) = 0;
    M2C_FIELD(a, s32 *, 0x2A8) = 0;
    M2C_FIELD(a, u16 *, 0x116) = 0x1535;
    func_80151DF4(play, M2C_FIELD(a, u16 *, 0x116));
    M2C_FIELD(a, void **, 0x284) = D_80BF2754;
}
