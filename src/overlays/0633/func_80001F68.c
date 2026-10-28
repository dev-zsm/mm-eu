// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800FFDD8(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80137070(s32);                         /* extern */

void func_80001F68(u8 *arg0, M2C_UNK arg1) {
    func_80137070(arg0 + 0x144);
    func_800FFDD8(arg0 + 0xBC, 0x3000, 6, 0x1000);
    if (M2C_FIELD(arg0, f32 *, 0x9C) > 100.0f) {
        func_800B6490(arg0);
    }
}
