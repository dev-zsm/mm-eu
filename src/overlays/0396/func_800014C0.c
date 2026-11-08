// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0396.h"

s32 func_800B8400(u8 *);                          /* extern */
extern M2C_UNK D_80AA3F84;

void func_800014C0(Actor *thisx) {
    if (func_800B8400(thisx) != 0) {
        M2C_FIELD(thisx, M2C_UNK **, 0x188) = &D_80AA3F84;
    }
}
