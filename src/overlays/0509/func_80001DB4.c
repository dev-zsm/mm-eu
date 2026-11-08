// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0509.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */

void func_80001DB4(Actor *thisx) {
    u8 *temp_a0;

    func_800B6490(thisx);
    temp_a0 = M2C_FIELD(thisx, u8 **, 0x2B8);
    if (temp_a0 != NULL) {
        func_800B6490(temp_a0);
    }
}
