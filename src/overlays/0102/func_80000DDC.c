#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFAD8(s32, f32, M2C_UNK, M2C_UNK, f32); /* extern */
M2C_UNK func_808C1C2C(u8 *);                      /* extern */
extern f32 D_808C2F24;

void func_80000DDC(u8 *arg0, M2C_UNK arg1) {
    func_800FFAD8(arg0 + 0x70, 0.0f, 0x3F800000, 0x3F000000, 0.0f);
    if ((M2C_FIELD(arg0, u16 *, 0x90) & 1) && (M2C_FIELD(arg0, f32 *, 0x70) < D_808C2F24)) {
        func_808C1C2C(arg0);
    }
}
