#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0456.h"

M2C_UNK func_800B5B64(s32, s32);                    /* extern */
M2C_UNK func_800F1944(s16);                         /* extern */
s32 func_800F1984(s16);                             /* extern */
M2C_UNK func_800F1A80(s16, u8 *);                 /* extern */
M2C_UNK func_800F1D6C(M2C_UNK);                     /* extern */
s32 func_800F1E2C();                                /* extern */
extern M2C_UNK D_80AF5598;
extern M2C_UNK D_80AF5BC8;
extern M2C_UNK D_80AF5E28;

void func_800017CC(u8 *arg0, s32 arg1) {
    s16 temp_v0;

    if (func_800F1984(((s16 *)(arg0 + 0x282))[M2C_FIELD(arg0, s16 *, 0x290)]) != 0) {
        temp_v0 = M2C_FIELD(arg0, s16 *, 0x1C);
        if ((temp_v0 & 7) == 1) {
            if (M2C_FIELD(arg0, s16 *, 0x290) != 2) {
                M2C_FIELD(arg0, M2C_UNK **, 0x218) = &D_80AF5BC8;
            } else {
                func_800B5B64(arg1, (s32) (temp_v0 & 0x7F8) >> 3);
                M2C_FIELD(arg0, M2C_UNK **, 0x218) = &D_80AF5598;
            }
        } else {
            M2C_FIELD(arg0, M2C_UNK **, 0x218) = &D_80AF5E28;
        }
        func_800F1A80(((s16 *)(arg0 + 0x282))[M2C_FIELD(arg0, s16 *, 0x290)], arg0);
        return;
    }
    if (func_800F1E2C() == 0x7C) {
        func_800F1D6C(0x7C);
    }
    func_800F1944(((s16 *)(arg0 + 0x282))[M2C_FIELD(arg0, s16 *, 0x290)]);
}
