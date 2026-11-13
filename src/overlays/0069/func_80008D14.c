#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0069.h"

M2C_UNK func_800B3B14(s32, f32, M2C_UNK, M2C_UNK); /* extern */
s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80137788(u8 *, M2C_UNK *, M2C_UNK, f32, f32, s32, f32); /* extern */
M2C_UNK func_8087B8E0(u8 *);                      /* extern */
M2C_UNK func_80883290(u8 *, s32);                 /* extern */
extern M2C_UNK D_600D4E8;

void func_80008D14(u8 *arg0, M2C_UNK arg1, s32 arg2) {
    func_800B3B14(arg0 + 0xBC, 0, 0, 0x41A00000);
    func_80883290(arg0, arg2);
    M2C_FIELD(arg0, s32 *, 0x380) = 8;
    func_80137788(arg0 + 0x1A4, &D_600D4E8, 0x3F800000, 0.0f, (f32) func_80134AE8(&D_600D4E8), 2, 0.0f);
    func_8087B8E0(arg0);
}
