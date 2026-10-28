// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_808CA324();                            /* extern */
M2C_UNK func_808CA4D0();                            /* extern */
M2C_UNK func_808CA74C();                            /* extern */
M2C_UNK func_808CA798();                            /* extern */
M2C_UNK func_808CAAE8();                            /* extern */
M2C_UNK func_808CABF4();                            /* extern */
M2C_UNK func_808CAD78();                            /* extern */

void func_80001760(u8 *arg0) {
    s16 temp_v0;
    u8 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x1C);
    if (temp_v0 == 6) {
        func_808CABF4();
        return;
    }
    if (temp_v0 == 2) {
        func_808CA4D0();
        return;
    }
    if (temp_v0 == 3) {
        func_808CA74C();
        return;
    }
    if (temp_v0 == 4) {
        temp_v0_2 = M2C_FIELD(arg0, u8 *, 0x148);
        if ((temp_v0_2 == 0) || (temp_v0_2 == 0xA)) {
            func_808CAAE8();
            return;
        }
        func_808CA798();
        return;
    }
    if (temp_v0 == 1) {
        func_808CA324();
        return;
    }
    if (temp_v0 == 5) {
        func_808CAD78();
    }
}
