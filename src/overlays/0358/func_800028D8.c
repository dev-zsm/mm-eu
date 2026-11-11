#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0358.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);                     /* extern */
M2C_UNK func_80A4D8CC(u8 *);                      /* extern */
extern M2C_UNK D_80A4FE38;
extern f32 D_80A50824;

void func_800028D8(u8 *arg0) {
    M2C_FIELD(arg0, s32 *, 0x30C) = (s32) (M2C_FIELD(arg0, s32 *, 0x30C) & ~1);
    M2C_FIELD(arg0, s16 *, 0x368) = 0x32;
    M2C_FIELD(arg0, f32 *, 0x160) = (f32) D_80A50824;
    func_800B8C4C(arg0, 0x39E9);
    func_80A4D8CC(arg0);
    M2C_FIELD(arg0, M2C_UNK **, 0x308) = &D_80A4FE38;
}
