#include "types.h"
#include "m2c_compat.h"

s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80137788(s32, M2C_UNK *, M2C_UNK, f32, f32, s32, f32); /* extern */
extern M2C_UNK D_6009D1C;
extern M2C_UNK D_80B7117C;

void func_80000CF8(u8 *arg0) {
    func_80137788(arg0 + 0x194, &D_6009D1C, 0x3F800000, 0, (f32) func_80134AE8(&D_6009D1C), 0, -8.0f);
    M2C_FIELD(arg0, s8 *, 0x300) = 0x3C;
    M2C_FIELD(arg0, M2C_UNK **, 0x308) = &D_80B7117C;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
}
