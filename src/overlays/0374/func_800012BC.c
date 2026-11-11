#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0374.h"

M2C_UNK func_800B680C(u8 *);                      /* extern */
M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800B8D94(u8 *, M2C_UNK);             /* extern */
s32 func_8013E684(u8 *, M2C_UNK, s16, M2C_UNK);   /* extern */
M2C_UNK func_80A7C88C(u8 *, s32);                 /* extern */
extern M2C_UNK D_80A7D3B4;

void func_800012BC(u8 *arg0, s32 arg1) {
    s32 temp_v0;

    if (M2C_FIELD(arg0, u16 *, 0x374) & 0x8000) {
        temp_v0 = M2C_FIELD(arg0, u16 *, 0x90);
        if (!(temp_v0 & 1)) {
            M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80A7D3B4;
            M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0x92);
            M2C_FIELD(arg0, s16 *, 0xBE) = (s16) M2C_FIELD(arg0, s16 *, 0x32);
            M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80A7D3B4;
            func_800B680C(arg0);
            func_800B8D94(arg0, 0x20A0);
            return;
        }
        if (temp_v0 & 2) {
            func_800B8C4C(arg0, 0x387A);
        }
        if (func_8013E684(arg0, 0x7C, M2C_FIELD(arg0, s16 *, 0x3D0), 1) != 0) {
            func_80A7C88C(arg0, arg1);
        }
    }
}
