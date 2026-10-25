#include "types.h"

s32 func_801A4814(s32 arg0, s32 arg1);

s32 func_801A55BC(void) {
    switch (func_801A4814(1, 1)) {
        case 0:
        case 8:
        case 16:
        case 24:
        case 32:
            return 1;
        default:
            return 0;
    }
}
