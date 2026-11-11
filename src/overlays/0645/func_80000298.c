// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0645.h"

s32 func_80000298(s32 arg0, s32 arg1, s32 *arg2, M2C_UNK arg3) {
    switch (arg1) {
    case 3:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
        *arg2 = 0;
        break;
    }
    return 0;
}
