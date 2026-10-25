#include "types.h"

s32 Player_BButtonSwordFromIA(u8 *arg0, s32 arg1) {
    s32 idx = arg1 - 2;
    s32 new_var;
    new_var = idx;
    if (((arg0[0x14B] != 1) && (idx > 0)) && (idx < 4)) {
        if (new_var) {
        }
        return idx;
    }
    return 0;
}
