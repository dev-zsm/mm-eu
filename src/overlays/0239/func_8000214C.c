// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0239.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80137828(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_6009A50;
extern M2C_UNK D_8097722C;

void func_8000214C(Actor *thisx) {
    M2C_FIELD(thisx, u8 *, 0x461) = (u8) (M2C_FIELD(thisx, u8 *, 0x461) & 0xFFFE);
    func_80137828((u8 *)thisx + 0x144, &D_6009A50, 0xC0800000, thisx);
    if (M2C_FIELD(thisx, u16 *, 0x90) & 1) {
        M2C_FIELD(thisx, f32 *, 0x70) = -4.0f;
    }
    M2C_FIELD(thisx, s16 *, 0x298) = 0;
    M2C_FIELD(thisx, s16 *, 0x32) = (s16) M2C_FIELD(thisx, s16 *, 0x92);
    func_800B8C4C(thisx, 0x3843);
    M2C_FIELD(thisx, M2C_UNK **, 0x290) = &D_8097722C;
}
