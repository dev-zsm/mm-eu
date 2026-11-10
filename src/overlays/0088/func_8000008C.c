#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490();                      /* extern */
extern M2C_UNK D_801E6EF0;

void func_8000008C(u8 *arg0) {
    switch (M2C_FIELD(&D_801E6EF0, s32 *, 0x18)) {  /* irregular */
        case 1:
        case 2:
            if (((s32) M2C_FIELD(&D_801E6EF0, u16 *, 0xC) < 0xE556) && ((s32) M2C_FIELD(&D_801E6EF0, u16 *, 0xC) >= 0x4001)) {
            if (M2C_FIELD(arg0, s16 *, 0x1C) != 0) {
                func_800B6490();
                return;
            }
            } else {
            if (M2C_FIELD(arg0, s16 *, 0x1C) == 0) {
                func_800B6490();
                return;
            }
            return;
            }
            break;
        case 3:
            if (M2C_FIELD(arg0, s16 *, 0x1C) == 0) {
            func_800B6490();
            }
            if ((((s32) M2C_FIELD(&D_801E6EF0, u16 *, 0xC) >= 0xEAAB) || ((s32) M2C_FIELD(&D_801E6EF0, u16 *, 0xC) < 0x4000)) && (M2C_FIELD(arg0, s16 *, 0x1C) != 0)) {
            func_800B6490();
            }
            break;
    }
}
