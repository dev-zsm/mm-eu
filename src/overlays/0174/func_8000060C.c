// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8093F5C0();                            /* extern */

void func_8000060C(u8 *arg0) {
    if (!(M2C_FIELD(arg0, s16 *, 0x3DA) & 0x3F)) {
        func_8093F5C0();
    }
}
