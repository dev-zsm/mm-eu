// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FF32C(u8 *, u8 *, u8 *);      /* extern */
extern M2C_UNK D_809D1C88;

void func_80000EB4(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x204) = &D_809D1C88;
    func_800FF32C(arg0 + 0x30, arg0 + 0xBC, arg0);
    M2C_FIELD(arg0, s16 *, 0x1F8) = 0;
    M2C_FIELD(arg0, s8 *, 0x1F6) = 1;
    M2C_FIELD(arg0, s16 *, 0x1FA) = 0x3C;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x74) = -3.0f;
}
