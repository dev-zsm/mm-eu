// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8014756C(u8 *);                      /* extern */

void func_80006248(u8 *arg0) {
    u8 *sp1C;
    u8 *temp_a0;

    temp_a0 = arg0 + 0x220;
    sp1C = temp_a0;
    func_8014756C(temp_a0);
    if (M2C_FIELD(temp_a0, s16 *, 0xC) == 0) {
        M2C_FIELD(arg0, s16 *, 0x24486) = 0x26;
    }
}
