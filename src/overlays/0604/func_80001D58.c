// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490();                            /* extern */
extern u8 D_801E7E25;
extern u8 D_801E7E26;
extern M2C_UNK D_80BD215C;
extern M2C_UNK D_80BD2420;
extern M2C_UNK D_80BD2644;
extern M2C_UNK D_80BD2928;
extern M2C_UNK D_80BD2B4C;
extern M2C_UNK D_80BD2E10;
extern M2C_UNK D_80BD3014;
extern M2C_UNK D_80BD32D0;

void func_80001D58(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v1;
    s32 temp_v0;

    temp_v1 = M2C_FIELD(arg0, s16 *, 0x1C);
    temp_v0 = temp_v1 & 3;
    switch (temp_v0) {                              /* irregular */
    case 0:
        if (D_801E7E25 & 0x10) {
            if (((s32) (temp_v1 & 4) >> 2) != 0) {
                M2C_FIELD(arg0, M2C_UNK **, 0x2DC) = &D_80BD2420;
                return;
            }
            func_800B6490();
            return;
        }
        if (((s32) (temp_v1 & 4) >> 2) != 0) {
            func_800B6490();
            return;
        }
        M2C_FIELD(arg0, M2C_UNK **, 0x2DC) = &D_80BD215C;
        return;
    case 1:
        if (D_801E7E25 & 0x80) {
            if (((s32) (temp_v1 & 4) >> 2) != 0) {
                M2C_FIELD(arg0, M2C_UNK **, 0x2DC) = &D_80BD2928;
                return;
            }
            func_800B6490();
            return;
        }
        if (((s32) (temp_v1 & 4) >> 2) != 0) {
            func_800B6490();
            return;
        }
        M2C_FIELD(arg0, M2C_UNK **, 0x2DC) = &D_80BD2644;
        return;
    case 2:
        if (D_801E7E26 & 4) {
            if (((s32) (temp_v1 & 4) >> 2) != 0) {
                M2C_FIELD(arg0, M2C_UNK **, 0x2DC) = &D_80BD2E10;
                return;
            }
            func_800B6490();
            return;
        }
        if (((s32) (temp_v1 & 4) >> 2) != 0) {
            func_800B6490();
            return;
        }
        M2C_FIELD(arg0, M2C_UNK **, 0x2DC) = &D_80BD2B4C;
        return;
    case 3:
        if (D_801E7E26 & 0x20) {
            if (((s32) (temp_v1 & 4) >> 2) != 0) {
                M2C_FIELD(arg0, M2C_UNK **, 0x2DC) = &D_80BD32D0;
                return;
            }
            func_800B6490();
            return;
        }
        if (((s32) (temp_v1 & 4) >> 2) != 0) {
            func_800B6490();
            return;
        }
        M2C_FIELD(arg0, M2C_UNK **, 0x2DC) = &D_80BD3014;
        return;
    }
}
