#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0308.h"

M2C_UNK func_800B3438(s32, u8 *, M2C_UNK *, M2C_UNK *, s32, s32); /* extern */
M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BD9E0(u8 *, M2C_UNK *, M2C_UNK);  /* extern */
extern M2C_UNK D_80A1130C;
extern M2C_UNK D_80A11818;
extern M2C_UNK D_80A118D0;
extern M2C_UNK D_80A118DC;

void func_800008D0(u8 *arg0, s32 arg1) {
    u8 *temp_v0;
    u8 *sp2C;

    temp_v0 = M2C_FIELD(arg0, u8 **, 0x120);
    if ((M2C_FIELD(arg0, s16 *, 0x1C) & 0xF) == 1) {
        sp2C = temp_v0;
        func_800B3438(arg1, arg0 + 0x24, &D_80A118D0, &D_80A118DC, 5, 2);
        M2C_FIELD(temp_v0, s16 *, 0x280) = (s16) (M2C_FIELD(temp_v0, s16 *, 0x280) + 0x64);
        M2C_FIELD(temp_v0, s16 *, 0x26E) = (s16) (M2C_FIELD(temp_v0, s16 *, 0x26E) + 1);
    } else {
        sp2C = temp_v0;
        func_800B3438(arg1, arg0 + 0x24, &D_80A118D0, &D_80A118DC, 5, 0);
        M2C_FIELD(temp_v0, s16 *, 0x280) = (s16) (M2C_FIELD(temp_v0, s16 *, 0x280) + 0x1E);
        M2C_FIELD(temp_v0, s16 *, 0x278) = (s16) (M2C_FIELD(temp_v0, s16 *, 0x278) + 1);
    }
    func_800B8C4C(arg0, 0x3880);
    M2C_FIELD(arg0, s16 *, 0x1E2) = 0;
    func_800BD9E0(arg0 + 0x144, &D_80A11818, 4);
    M2C_FIELD(arg0, s16 *, 0x1D8) = 0xA0;
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80A1130C;
}
