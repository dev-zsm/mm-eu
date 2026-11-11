#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_801378E0(s32, M2C_UNK *, u8 *);      /* extern */
extern M2C_UNK D_6000444;
extern M2C_UNK D_808BF22C;

void func_80000894(u8 *arg0) {
    func_801378E0(arg0 + 0x144, &D_6000444, arg0);
    M2C_FIELD(arg0, u8 *, 0x394) = (u8) (M2C_FIELD(arg0, u8 *, 0x394) | 1);
    M2C_FIELD(arg0, s16 *, 0x250) = 0xC8;
    M2C_FIELD(arg0, s8 *, 0x24C) = 0;
    M2C_FIELD(arg0, u8 *, 0x395) = (u8) (M2C_FIELD(arg0, u8 *, 0x395) | 1);
    M2C_FIELD(arg0, f32 *, 0x70) = 2.0f;
    M2C_FIELD(arg0, f32 *, 0x254) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x258) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x74) = -2.0f;
    func_800B8C4C(arg0, 0x38CD);
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
    M2C_FIELD(arg0, M2C_UNK **, 0x248) = &D_808BF22C;
}
