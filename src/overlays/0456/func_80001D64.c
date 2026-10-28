// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80AF4B48(M2C_UNK);                     /* extern */
extern s16 D_801E7F08;

void func_80001D64(s32 arg0, M2C_UNK arg1) {
    if (D_801E7F08 == 0) {
        func_80AF4B48(arg1);
    }
}
