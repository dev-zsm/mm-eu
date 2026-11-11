#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0076.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_801377D0(s32, M2C_UNK *, u8 *);      /* extern */
extern M2C_UNK D_60025B4;
extern M2C_UNK D_8089BC8C;

void func_80001E18(u8 *arg0) {
    func_801377D0(arg0 + 0x144, &D_60025B4, arg0);
    M2C_FIELD(arg0, u8 *, 0x5D4) = (u8) (M2C_FIELD(arg0, u8 *, 0x5D4) & 0xFFFB);
    func_800B8C4C(arg0, 0x3829);
    M2C_FIELD(arg0, s16 *, 0x290) = 0;
    M2C_FIELD(arg0, s16 *, 0x292) = -1;
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
    M2C_FIELD(arg0, M2C_UNK **, 0x284) = &D_8089BC8C;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
}
