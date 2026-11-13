#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80874224();                            /* extern */
M2C_UNK func_80874968(u8 *);                      /* extern */
M2C_UNK func_80874B10(u8 *, M2C_UNK);             /* extern */

void func_800011FC(u8 *arg0) {
    if (M2C_FIELD(arg0, s16 *, 0x18E) != 0) {
        M2C_FIELD(arg0, s16 *, 0x18E) = (s16) (M2C_FIELD(arg0, s16 *, 0x18E) - 1);
    }
    if (M2C_FIELD(arg0, s16 *, 0x18E) == 0) {
        func_80874224();
        if (M2C_FIELD(arg0, u8 *, 0xB7) == 0) {
            func_80874B10(arg0, 0);
            return;
        }
        M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
        func_80874968(arg0);
    }
}
