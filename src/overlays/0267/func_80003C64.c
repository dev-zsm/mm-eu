#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0267.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80137070(u8 *);                      /* extern */
M2C_UNK func_80137828(u8 *, M2C_UNK *, f32);  /* extern */
M2C_UNK func_8099B268(u8 *, s32);                 /* extern */
extern M2C_UNK D_60005A8;
extern M2C_UNK D_60009E0;

void func_80003C64(u8 *arg0, s32 arg1) {
    s16 temp_v0;
    u8 *temp_a0;

    M2C_FIELD(arg0, s8 *, 0x680) = 1;
    if (M2C_FIELD(arg0, u8 *, 0x148) != 0) {
        func_80137070(arg0 + 0x194);
    }
    switch (M2C_FIELD(arg0, u8 *, 0x148)) {         /* irregular */
        case 0:
            break;
        case 1:
            temp_a0 = arg0 + 0x194;
            if (M2C_FIELD(arg0, u8 *, 0x290) == 0) {
            func_80137828(temp_a0, &D_60009E0, 0);
            } else {
            func_80137828(temp_a0, &D_60005A8, 0);
            }
            func_800B8C4C(arg0, 0x3A2A);
            M2C_FIELD(arg0, u8 *, 0x290) = (u8) (1 - M2C_FIELD(arg0, u8 *, 0x290));
            M2C_FIELD(arg0, u8 *, 0x148) = 2U;
            M2C_FIELD(arg0, s16 *, 0x14A) = 2;
            /* fallthrough */
        case 2:
            if (M2C_FIELD(arg0, s16 *, 0x14A) == 1) {
            if (M2C_FIELD(arg0, u8 *, 0x290) == 0) {
                func_800B8C4C(arg0, 0x3A2E);
            } else {
                func_800B8C4C(arg0, 0x3A2F);
            }
            }
            if (M2C_FIELD(arg0, u8 *, 0x151) == 0) {
            func_8099B268(arg0, arg1);
            M2C_FIELD(arg0, f32 *, 0x1AC) = 25.0f;
            }
            break;
    }
    M2C_FIELD(arg0, s16 *, 0x18A) = 0;
    temp_v0 = M2C_FIELD(arg0, s16 *, 0x18A);
    M2C_FIELD(arg0, s16 *, 0x188) = temp_v0;
    M2C_FIELD(arg0, s16 *, 0x186) = temp_v0;
    M2C_FIELD(arg0, s16 *, 0x184) = temp_v0;
}
