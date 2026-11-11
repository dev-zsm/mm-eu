#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0564.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800B6564(u8 *, f32);                         /* extern */
extern M2C_UNK D_801E6EF0;
extern f32 D_80BB1AA0;

void func_800005D8(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, f32 *, 0x350) = (f32) (M2C_FIELD(arg0, f32 *, 0x350) * D_80BB1AA0);
    func_800B6564(arg0, M2C_FIELD(arg0, f32 *, 0x350));
    if (M2C_FIELD(arg0, u16 *, 0x90) & 1) {
        M2C_FIELD(&D_801E6EF0, u8 *, 0xF2C) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF2C) | 0x40);
        func_800B6490(arg0);
    }
}
