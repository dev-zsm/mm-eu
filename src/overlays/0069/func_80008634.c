#include "types.h"
#include "m2c_compat.h"

s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80137788(u8 *, M2C_UNK *, f32, f32, f32, s32, f32); /* extern */
M2C_UNK func_80883290(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_600A8DC;

void func_80008634(u8 *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    func_80883290(arg0, arg2);
    M2C_FIELD(arg0, s32 *, 0x3E0) = 2;
    func_80137788(arg0 + 0x1A4, &D_600A8DC, 0.0f, 0.0f, (f32) func_80134AE8(&D_600A8DC), 2, 0.0f);
}
