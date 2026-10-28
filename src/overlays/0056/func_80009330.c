// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800C9B6C(s32, s32, u8);                    /* extern */
M2C_UNK func_8082D16C(u8 *);                      /* extern */
M2C_UNK func_8082D8A0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_8082DAE8(s32, u8 *, M2C_UNK *);      /* extern */
M2C_UNK func_80830B44(s32, u8 *, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_8083643C(u8 *);                      /* extern */
extern M2C_UNK D_400E270;
extern M2C_UNK D_800B3F30;
extern u8 *D_801EB7E0;
extern M2C_UNK D_808558A4;

s32 func_80009330(s32 arg0, u8 *arg1) {
    if ((M2C_FIELD(D_801EB7E0, s16 *, 0x434) != 0) || (func_800C9B6C(arg0 + 0x830, M2C_FIELD(arg1, s32 *, 0x80), M2C_FIELD(arg1, u8 *, 0x85)) != 0)) {
        func_80830B44(arg0, arg1, &D_808558A4, 0);
        M2C_FIELD(arg1, s32 *, 0xA6C) = (s32) (M2C_FIELD(arg1, s32 *, 0xA6C) & 0xBFFDFFFF);
        func_8082DAE8(arg0, arg1, &D_400E270);
        func_8082D16C(arg1);
        func_8083643C(arg1);
        M2C_FIELD(arg1, M2C_UNK **, 0xC8) = &D_800B3F30;
        M2C_FIELD(arg1, f32 *, 0xB48) = -2000.0f;
        M2C_FIELD(arg1, f32 *, 0xCC) = 13.0f;
        func_8082D8A0(arg1, 0x8E2);
        return 1;
    }
    return 0;
}
