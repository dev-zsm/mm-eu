#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0072.h"

s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80137788(s32, M2C_UNK *, M2C_UNK, f32, f32, s32, f32); /* extern */
f32 func_8017A844(f32);                             /* extern */
extern M2C_UNK D_60000E8;
extern M2C_UNK D_80891BD0;
extern f32 D_80892C90;

void func_800013B4(u8 *arg0) {
    s32 temp_t7;

    func_80137788(arg0 + 0x144, &D_60000E8, 0x3F800000, 0, (f32) func_80134AE8(&D_60000E8), 0, -10.0f);
    temp_t7 = (s32) func_8017A844(D_80892C90);
    M2C_FIELD(arg0, s16 *, 0x29A) = (s16) temp_t7;
    M2C_FIELD(arg0, s16 *, 0x28E) = 7;
    M2C_FIELD(arg0, M2C_UNK **, 0x248) = &D_80891BD0;
    M2C_FIELD(arg0, f32 *, 0x70) = 4.0f;
}
