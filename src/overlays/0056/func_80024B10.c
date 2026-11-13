#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0056.h"

M2C_UNK func_80851424();                            /* extern */
M2C_UNK func_808518D4();                            /* extern */
M2C_UNK func_80851984();                            /* extern */

void func_80024B10(s32 arg0, u8 *arg1) {
    u32 temp_v0;

    temp_v0 = M2C_FIELD(arg1, u8 *, 0x14B);
    if (temp_v0 == 3) {
        func_80851424();
        return;
    }
    if (temp_v0 == 1) {
        func_808518D4(arg0);
        return;
    }
    if (temp_v0 == 2) {
        func_80851984();
    }
}
