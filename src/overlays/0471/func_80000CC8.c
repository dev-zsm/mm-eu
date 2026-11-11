#include "types.h"
#include "m2c_compat.h"

extern s16 D_80B0AA74;
extern s16 D_80B0AA7C;

void func_80000CC8(u8 *arg0) {
    if ((M2C_FIELD(arg0, s32 *, 0x1E8) >= 9) && (M2C_FIELD(arg0, s16 *, 0x29C) == 0)) {
        M2C_FIELD(arg0, s16 *, 0x29C) = 1;
    }
    if ((M2C_FIELD(arg0, s32 *, 0x1E8) >= 0xB) && (M2C_FIELD(arg0, s16 *, 0x29C) == 1)) {
        M2C_FIELD(arg0, s16 *, 0x29C) = 2;
    }
    if (((M2C_FIELD(arg0, s32 *, 0x1E8) >= D_80B0AA74) || (M2C_FIELD(arg0, s16 *, 0x29C) <= 0)) && (D_80B0AA74 < M2C_FIELD(arg0, s32 *, 0x1E8))) {
        D_80B0AA74 = (s16) M2C_FIELD(arg0, s32 *, 0x1E8);
        D_80B0AA7C = M2C_FIELD(arg0, s16 *, 0x290);
    }
}
