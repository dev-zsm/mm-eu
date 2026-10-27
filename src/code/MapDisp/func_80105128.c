#include "types.h"

s32 MapDisp_IsBossDoor(s32 arg0) {
    // the narrowing through char is needed for the ROM's codegen
    char temp = arg0 >> 7;

    if ((temp & 7) == 5) {
        return 1;
    }
    return 0;
}
