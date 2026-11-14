#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0074.h"

M2C_UNK func_801378E0(s32, M2C_UNK *, u8 *);      /* extern */
extern M2C_UNK D_60005C4;
extern M2C_UNK D_808971B4;
extern f32 D_80898CFC;

void func_80000B04(u8 *arg0) {
    func_801378E0(arg0 + 0x144, &D_60005C4, arg0);
    M2C_FIELD(arg0, s16 *, 0x2B0) = 0x1E;
    M2C_FIELD(arg0, f32 *, 0x70) = (f32) D_80898CFC;
    M2C_FIELD(arg0, u8 *, 0x478) = (u8) (M2C_FIELD(arg0, u8 *, 0x478) | 1);
    M2C_FIELD(arg0, M2C_UNK **, 0x2A8) = &D_808971B4;
}
