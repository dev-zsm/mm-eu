// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80137788(s32, M2C_UNK *, M2C_UNK, f32, f32, s32, f32); /* extern */
M2C_UNK func_80AFBCF0(u8 *, s32);                 /* extern */
extern M2C_UNK D_600554C;
extern M2C_UNK D_80AFCD10;

void func_8000144C(u8 *arg0, s32 arg1) {
    func_80137788(arg0 + 0x144, &D_600554C, 0xBF800000, (f32) func_80134AE8(&D_600554C), 0.0f, 2, -3.0f);
    func_80AFBCF0(arg0, arg1);
    func_800B8C4C(arg0, 0x396C);
    M2C_FIELD(arg0, M2C_UNK **, 0x280) = &D_80AFCD10;
}
