#include "types.h"
#include "m2c_compat.h"

u32 func_80087010();                                /* extern */
s32 func_800B6AB0(u8 *, u8 *);                  /* extern */
M2C_UNK func_801377D0(s32, M2C_UNK *);              /* extern */
extern M2C_UNK D_60069FC;
extern M2C_UNK D_808E9CA8;

void func_80005568(u8 *arg0) {
    func_801377D0(arg0 + 0x144, &D_60069FC);
    M2C_FIELD(arg0, s16 *, 0x2BA) = 0x3C;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    if ((s16) (func_800B6AB0(arg0, arg0 + 8) - M2C_FIELD(arg0, s16 *, 0x2D0)) > 0) {
        M2C_FIELD(arg0, s16 *, 0x2B6) = (s16) (M2C_FIELD(arg0, s16 *, 0x2D0) + (func_80087010() >> 0x14)+ 0x2000);
    } else {
        M2C_FIELD(arg0, s16 *, 0x2B6) = (s16) ((M2C_FIELD(arg0, s16 *, 0x2D0) - (func_80087010() >> 0x14)) - 0x2000);
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808E9CA8;
}
