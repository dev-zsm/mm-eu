#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0069.h"

s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80137788(u8 *, M2C_UNK *, M2C_UNK, f32, f32, s32, f32); /* extern */
M2C_UNK func_80883290(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_600AD08;

void func_800087E8(u8 *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    func_80883290(arg0, arg2);
    M2C_FIELD(arg0, s32 *, 0x3E0) = 4;
    func_80137788(arg0 + 0x1A4, &D_600AD08, 0x3F800000, 0, (f32) func_80134AE8(&D_600AD08), 2, -3.0f);
}
