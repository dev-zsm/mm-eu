#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0489.h"

M2C_UNK func_800BC8F4(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_801378E0(u8 *, M2C_UNK *);           /* extern */
extern M2C_UNK D_60006C8;
extern M2C_UNK D_80B2C624;
extern M2C_UNK D_80B32844;

void func_80003E80(u8 *arg0) {
    M2C_FIELD(arg0, u8 *, 0x2B0) = (u8) (M2C_FIELD(arg0, u8 *, 0x2B0) & ~1);
    M2C_FIELD(arg0, u8 *, 0x2B1) = (u8) (M2C_FIELD(arg0, u8 *, 0x2B1) & ~1);
    M2C_FIELD(arg0, u8 *, 0x2B2) = (u8) (M2C_FIELD(arg0, u8 *, 0x2B2) | 1);
    func_801378E0(arg0 + 0x144, &D_60006C8);
    func_800BC8F4(arg0, 0x4000, 0xFF, 0, 0x10);
    M2C_FIELD(arg0, u8 *, 0x389) = 0xFF;
    M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80B32844;
    M2C_FIELD(arg0, s8 *, 0x38B) = 1;
    M2C_FIELD(arg0, s8 *, 0x38C) = 0;
    M2C_FIELD(arg0, s8 *, 0x38D) = 0;
    M2C_FIELD(arg0, s16 *, 0x2F0) = 8;
    M2C_FIELD(arg0, s16 *, 0x2F2) = 0;
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x80000000);
    M2C_FIELD(arg0, M2C_UNK **, 0x2EC) = &D_80B2C624;
}
