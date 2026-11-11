#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0239.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80137828(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_60053D0;
extern M2C_UNK D_80977B4C;

void func_80002A5C(u8 *arg0) {
    M2C_FIELD(arg0, u8 *, 0x461) = (u8) (M2C_FIELD(arg0, u8 *, 0x461) & 0xFFFE);
    func_80137828(arg0 + 0x144, &D_60053D0, 0xC0800000, arg0);
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0x92);
    if (M2C_FIELD(arg0, u16 *, 0x90) & 1) {
        M2C_FIELD(arg0, f32 *, 0x70) = -6.0f;
    }
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~1);
    M2C_FIELD(arg0, s16 *, 0x2A0) = 0x19;
    func_800B8C4C(arg0, 0x384B);
    M2C_FIELD(arg0, M2C_UNK **, 0x290) = &D_80977B4C;
}
