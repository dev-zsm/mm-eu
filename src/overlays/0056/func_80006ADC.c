#include "types.h"
#include "m2c_compat.h"

s32 func_80833BE4();                                /* extern */

s32 func_80006ADC(s32 arg0, u8 *arg1) {
    if (M2C_FIELD(arg1, u8 *, 0xBB) == 1) {
        return func_80833BE4(arg0, arg1);
    }
    return 0;
}
