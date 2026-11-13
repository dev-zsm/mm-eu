#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0496.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);                     /* extern */
extern M2C_UNK D_80B46EFC;

void func_80000B74(u8 *arg0) {
    M2C_FIELD(arg0, u8 *, 0x2BD) = (u8) (M2C_FIELD(arg0, u8 *, 0x2BD) & ~1);
    M2C_FIELD(arg0, u8 *, 0x2BE) = (u8) (M2C_FIELD(arg0, u8 *, 0x2BE) & ~1);
    M2C_FIELD(arg0, s16 *, 0x20A) = 0x2000;
    M2C_FIELD(arg0, s16 *, 0x206) = 0x20;
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, u32 *, 4) & ~1);
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    func_800B8C4C(arg0, 0x3874);
    M2C_FIELD(arg0, M2C_UNK **, 0x200) = &D_80B46EFC;
}
