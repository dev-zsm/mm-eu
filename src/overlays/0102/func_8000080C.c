#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_801378E0(s32, M2C_UNK *, u8 *);      /* extern */
extern M2C_UNK D_6000444;
extern M2C_UNK D_808C1CC0;

void func_8000080C(u8 *arg0) {
    func_801378E0(arg0 + 0x144, &D_6000444, arg0);
    M2C_FIELD(arg0, u8 *, 0x304) = (u8) (M2C_FIELD(arg0, u8 *, 0x304) | 1);
    M2C_FIELD(arg0, s16 *, 0x250) = 0x8C;
    M2C_FIELD(arg0, u8 *, 0x305) = (u8) (M2C_FIELD(arg0, u8 *, 0x305) | 1);
    M2C_FIELD(arg0, f32 *, 0x70) = 2.0f;
    M2C_FIELD(arg0, f32 *, 0x268) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x264) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x74) = -2.0f;
    func_800B8C4C(arg0, 0x38CD);
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
    M2C_FIELD(arg0, M2C_UNK **, 0x248) = &D_808C1CC0;
}
