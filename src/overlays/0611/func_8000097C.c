// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801520F8(s32, M2C_UNK);                /* extern */
extern u8 D_801E7E33;

void func_8000097C(s32 arg0) {
    if (D_801E7E33 & 0x80) {
        func_801520F8(arg0, 0x27);
    }
    func_801520F8(arg0, 0xC);
}
