#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0488.h"

s32 func_800B8254(u8 *, s32);                     /* extern */
M2C_UNK func_800B8284(u8 *, s32, f32, f32, s32); /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
M2C_UNK func_80B25B48(u8 *, u16);                 /* extern */
M2C_UNK func_80B25F0C(u8 *, s32, M2C_UNK);        /* extern */
extern M2C_UNK D_80B26B48;

void func_800014BC(u8 *arg0, s32 arg1) {
    func_80137070(arg0 + 0x144);
    if (func_800B8254(arg0, arg1) != 0) {
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & 0xFFFEFFFF);
        func_80B25B48(arg0, M2C_FIELD(arg0, u16 *, 0x116));
        M2C_FIELD(arg0, M2C_UNK **, 0x304) = &D_80B26B48;
        func_80B25F0C(arg0, arg1, 4);
        return;
    }
    func_800B8284(arg0, arg1, 1.0e+03f, 1.0e+03f, -1);
}
