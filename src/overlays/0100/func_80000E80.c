#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFAD8(s32, f32, M2C_UNK, M2C_UNK, f32); /* extern */
s32 func_808BEB18(u8 *, s32);                     /* extern */
M2C_UNK func_808BF0F8(u8 *);                      /* extern */
M2C_UNK func_808BF194(u8 *);                      /* extern */
extern f32 D_808C0504;

void func_80000E80(u8 *arg0, s32 arg1) {
    func_800FFAD8(arg0 + 0x70, 0.0f, 0x3F800000, 0x3F000000, 0.0f);
    if ((M2C_FIELD(arg0, u16 *, 0x90) & 1) && (M2C_FIELD(arg0, f32 *, 0x70) < D_808C0504)) {
        if (func_808BEB18(arg0, arg1) != 0) {
            func_808BF0F8(arg0);
            return;
        }
        func_808BF194(arg0);
    }
}
