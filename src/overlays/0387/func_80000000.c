#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0387.h"

s16 func_800FF250(M2C_UNK, M2C_UNK, u8 *);        /* extern */

void func_80000000(u8 *arg0) {
    s16 temp_v0;
    s16 temp_v0_2;
    s16 temp_v0_3;
    s16 temp_v0_4;
    switch ((M2C_FIELD(arg0, u8 *, 0x200))) {
        case 0:
            temp_v0 = M2C_FIELD(arg0, s16 *, 0x1F8);
            M2C_FIELD(arg0, s8 *, 0x201) = 0;
            if (temp_v0 > 0) {
            M2C_FIELD(arg0, s16 *, 0x1F8) = (s16) (temp_v0 - 1);
            } else {
            M2C_FIELD(arg0, s16 *, 0x1F8) = 0;
            }
            temp_v0_2 = M2C_FIELD(arg0, s16 *, 0x1F8);
            if (temp_v0_2 < 4) {
            M2C_FIELD(arg0, s8 *, 0x201) = (s8) temp_v0_2;
            }
            if (temp_v0_2 == 0) {
            M2C_FIELD(arg0, s16 *, 0x1F8) = func_800FF250(0x1E, 0x1E, arg0);
            return;
            }
        default:
            return;
        case 1:
            temp_v0_3 = M2C_FIELD(arg0, s16 *, 0x1F8);
            M2C_FIELD(arg0, s8 *, 0x201) = 4;
            if (temp_v0_3 > 0) {
            M2C_FIELD(arg0, s16 *, 0x1F8) = (s16) (temp_v0_3 - 1);
            } else {
            M2C_FIELD(arg0, s16 *, 0x1F8) = 0;
            }
            temp_v0_4 = M2C_FIELD(arg0, s16 *, 0x1F8);
            if (temp_v0_4 < 4) {
            M2C_FIELD(arg0, s8 *, 0x201) = (s8) (temp_v0_4 + 4);
            }
            if (temp_v0_4 == 0) {
            M2C_FIELD(arg0, s16 *, 0x1F8) = func_800FF250(0x1E, 0x1E, arg0);
            return;
            }
            break;
        case 2:
            M2C_FIELD(arg0, s8 *, 0x201) = 2;
            return;
        case 3:
            M2C_FIELD(arg0, s8 *, 0x201) = 4;
            return;
        case 5:
            M2C_FIELD(arg0, s8 *, 0x201) = 8;
            break;
    }
}
