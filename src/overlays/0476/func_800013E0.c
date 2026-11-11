#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0476.h"

M2C_UNK func_80137934(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_60006E0;
extern M2C_UNK D_80B12874;

void func_800013E0(u8 *arg0) {
    func_80137934(arg0 + 0x144, &D_60006E0, 0xC0A00000, arg0);
    M2C_FIELD(arg0, f32 *, 0x70) = 5.0f;
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) (M2C_FIELD(arg0, s16 *, 0xBE) + 0x8000);
    M2C_FIELD(arg0, u8 *, 0x33D) = (u8) (M2C_FIELD(arg0, u8 *, 0x33D) | 1);
    M2C_FIELD(arg0, s16 *, 0x18E) = 0xC8;
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80B12874;
}
