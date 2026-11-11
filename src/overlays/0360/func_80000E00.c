#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0360.h"

s32 func_800B8254(u8 *, u8 *);                  /* extern */
M2C_UNK func_800B8364(u8 *, u8 *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80151DF4(u8 *, M2C_UNK, u8 *);     /* extern */
M2C_UNK func_801520F8(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80A54728(u8 *);                      /* extern */

void func_80000E00(u8 *arg0, u8 *arg1) {
    u8 *temp_v1;
    u8 *sp24;

    temp_v1 = M2C_FIELD(arg1, u8 **, 0x1CCC);
    sp24 = temp_v1;
    if (func_800B8254(arg0, arg1) != 0) {
        M2C_FIELD(temp_v1, s32 *, 0xA6C) = (s32) (M2C_FIELD(temp_v1, s32 *, 0xA6C) & ~0x20);
        func_80151DF4(arg1, 0x2794, arg0);
        M2C_FIELD(arg0, s16 *, 0x2B4) = 0x2794;
        func_801520F8(arg1, 0xB);
        func_801520F8(arg1, 0x2B);
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & 0xFFFEFFFF);
        func_80A54728(arg0);
        return;
    }
    func_800B8364(arg0, arg1, 0x43480000, -1);
}
