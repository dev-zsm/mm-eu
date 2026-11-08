// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0506.h"

void func_80001F70(Actor *thisx, s16 arg1) {
    u8 *temp_v0;

    temp_v0 = M2C_FIELD(thisx, u8 **, 0x120);
    if (temp_v0 == NULL) {
        M2C_FIELD(thisx, s16 *, 0x3F8) = arg1;
        return;
    }
    M2C_FIELD(temp_v0, s16 *, 0x3F8) = arg1;
}
