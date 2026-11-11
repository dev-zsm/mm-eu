#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0553.h"

s32 func_800B8254(u8 *, s32);                     /* extern */
M2C_UNK func_800B8284(u8 *, s32, f32, f32, s32); /* extern */
M2C_UNK func_80151DF4(s32, M2C_UNK, u8 *);        /* extern */
extern M2C_UNK D_80BA064C;

void func_80000624(u8 *arg0, s32 arg1) {
    if (func_800B8254(arg0, arg1) != 0) {
        func_80151DF4(arg1, 0x124F, arg0);
        M2C_FIELD(arg0, M2C_UNK **, 0x2C0) = &D_80BA064C;
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & 0xFFFEFFFF);
        return;
    }
    func_800B8284(arg0, arg1, 1.0e+03f, 1.0e+03f, -1);
}
