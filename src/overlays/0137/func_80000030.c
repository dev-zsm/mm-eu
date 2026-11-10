#include "types.h"
#include "m2c_compat.h"

s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80137788(s32, M2C_UNK *, M2C_UNK, f32, f32, s32, f32); /* extern */
extern M2C_UNK D_402F0EC;

void func_80000030(s32 arg0) {
    func_80137788(arg0 + 0x1A4, &D_402F0EC, 0x3F800000, 0, (f32) func_80134AE8(&D_402F0EC), 1, 2.0f);
}
