// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80137828(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_6009A50;
extern M2C_UNK D_8097722C;

void func_8000214C(u8 *arg0) {
    M2C_FIELD(arg0, u8 *, 0x461) = (u8) (M2C_FIELD(arg0, u8 *, 0x461) & 0xFFFE);
    func_80137828(arg0 + 0x144, &D_6009A50, 0xC0800000, arg0);
    if (M2C_FIELD(arg0, u16 *, 0x90) & 1) {
        M2C_FIELD(arg0, f32 *, 0x70) = -4.0f;
    }
    M2C_FIELD(arg0, s16 *, 0x298) = 0;
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0x92);
    func_800B8C4C(arg0, 0x3843);
    M2C_FIELD(arg0, M2C_UNK **, 0x290) = &D_8097722C;
}
