// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_801367B4(s32, u8 *, M2C_UNK *, M2C_UNK, f32, f32, s32, f32); /* extern */
M2C_UNK func_80830B44(s32, u8 *, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK D_400D3F8;
extern M2C_UNK D_8084A97C;

void func_8000D524(u8 *arg0, s16 arg1, s32 arg2) {
    func_80830B44(arg2, arg0, &D_8084A97C, 1);
    func_801367B4(arg2, arg0 + 0x240, &D_400D3F8, 0x3F800000, 0.0f, (f32) func_80134AE8(&D_400D3F8), 2, -6.0f);
    M2C_FIELD(arg0, f32 *, 0xAD0) = 8.0f;
    M2C_FIELD(arg0, s16 *, 0xAD4) = arg1;
}
