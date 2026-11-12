#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0243.h"

M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
M2C_UNK func_8097F998(u8 *);                      /* extern */

void func_80000D08(u8 *arg0, M2C_UNK arg1) {
    u32 temp_v0;

    func_80137070(arg0 + 0x144);
    if (M2C_FIELD(arg0, u16 *, 0x90) & 8) {
        M2C_FIELD(arg0, s16 *, 0x192) = (s16) M2C_FIELD(arg0, s16 *, 0x86);
    } else {
        M2C_FIELD(arg0, s16 *, 0x192) = (s16) (M2C_FIELD(arg0, s16 *, 0x92) + 0x8000);
    }
    func_800FFCBC(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x192), 3, 0xC00, 0xC0);
    func_800FFCBC(arg0 + 0xBC, M2C_FIELD(arg0, s16 *, 0x190), 5, 0x100, 0x10);
    if (M2C_FIELD(arg0, s16 *, 0x18E) != 0) {
        temp_v0 = M2C_FIELD(arg0, s16 *, 0x18E);
        M2C_FIELD(arg0, s16 *, 0x18E) = (s16) (temp_v0 - 1);
    }
    if (M2C_FIELD(arg0, s16 *, 0x18E) == 0) {
        func_8097F998(arg0);
    }
}
