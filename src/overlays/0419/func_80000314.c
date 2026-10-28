// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800C604C(s32, s32, s32);               /* extern */
M2C_UNK func_800CABA0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800CABC4(s32, u8 *, M2C_UNK *);      /* extern */
M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
extern M2C_UNK D_6016E70;
extern M2C_UNK D_6018588;
extern M2C_UNK D_80AB7D84;
extern M2C_UNK D_80AB7FF4;
extern M2C_UNK D_80AB8000;
extern M2C_UNK D_80AB800C;

void func_80000314(u8 *arg0, s32 arg1) {
    s32 temp_s1;

    temp_s1 = M2C_FIELD(arg0, s16 *, 0x1C) & 3;
    func_800B6564(arg0, 0x3DCCCCCD);
    if (temp_s1 == 1) {
        func_800FF8DC(arg0, &D_80AB8000);
    } else if (temp_s1 == 3) {
        func_800FF8DC(arg0, &D_80AB800C);
        M2C_FIELD(arg0, s32 *, 0x13C) = 0;
        M2C_FIELD(arg0, M2C_UNK **, 0x138) = &D_80AB7D84;
    } else {
        func_800FF8DC(arg0, &D_80AB7FF4);
    }
    if (temp_s1 == 2) {
        func_800CABA0(arg0, 3);
        func_800CABC4(arg1, arg0, &D_6018588);
        return;
    }
    if (temp_s1 == 3) {
        func_800CABA0(arg0, 0);
        func_800CABC4(arg1, arg0, &D_6016E70);
        func_800C604C(arg1, arg1 + 0x880, M2C_FIELD(arg0, s32 *, 0x144));
    }
}
