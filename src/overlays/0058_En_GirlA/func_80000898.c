// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80114D8C();
extern s16 D_801E6F2A;

s32 EnGirlA_CanBuyFairy(u8 *arg0, s32 arg1) {
    if (func_80114D8C() == 0) {
        return 3;
    }
    if (D_801E6F2A < M2C_FIELD(arg0, s32 *, 0x16978)) {
        return 4;
    }
    return 1;
}
