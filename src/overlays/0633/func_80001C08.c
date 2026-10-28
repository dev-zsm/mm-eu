// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80137070(u8 *);                      /* extern */
M2C_UNK func_80BF62D8(u8 *);                      /* extern */

void func_80001C08(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x18E);
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, s16 *, 0x18E) = (s16) (temp_v0 - 1);
    }
    func_80137070(arg0 + 0x144);
    if (M2C_FIELD(arg0, u16 *, 0x90) & 8) {
        M2C_FIELD(arg0, s16 *, 0x192) = (s16) M2C_FIELD(arg0, s16 *, 0x86);
    } else {
        M2C_FIELD(arg0, s16 *, 0x192) = (s16) (M2C_FIELD(arg0, s16 *, 0x92) + 0x8000);
    }
    func_800FFCBC(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x192), 6, 0x1000, 0x100);
    func_800FFCBC(arg0 + 0xBC, M2C_FIELD(arg0, s16 *, 0x190), 5, 0x100, 0x10);
    if (M2C_FIELD(arg0, s16 *, 0x18E) == 0) {
        func_80BF62D8(arg0);
    }
}
