// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80136480();
void func_8082EAEC();
extern u8 D_80848260;

s32 func_8001B608(u8 *arg0, s32 arg1) {
    if (!(M2C_FIELD(arg0, u16 *, 0x90) & 1) || func_80136480(arg1, arg0 + 0x284) != 0) {
        func_8082EAEC(arg1, arg0, &D_80848260);
    }
    return 1;
}
