#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0328.h"

s32 func_800B8400(u8 *, s32);                          /* extern */
M2C_UNK func_80A23530(u8 *, M2C_UNK *);           /* extern */
s32 func_80A2355C(u8 *, s32, s32);                /* extern */
s32 func_80A23A74(u8 *, s32);                     /* extern */
extern M2C_UNK D_80A253C8;
extern M2C_UNK D_80A25574;
extern M2C_UNK D_80A25658;

void func_8000206C(u8 *arg0, s32 arg1) {
    u8 temp_v0;

    if (func_800B8400(arg0, arg1) != 0) {
        temp_v0 = M2C_FIELD(M2C_FIELD(arg0, u8 **, 0xD78), u8 *, 1);
        if ((temp_v0 == 0) || (func_80A2355C(arg0, arg1, temp_v0 - 1) == 0)) {
            if (!(((s16) M2C_FIELD(arg0, s16 *, 0x1C) >> 5) & 0xF)) {
                func_80A23530(arg0, &D_80A25574);
            } else {
                func_80A23530(arg0, &D_80A253C8);
            }
            M2C_FIELD(arg0, s32 *, 0x730) = 0;
        }
    } else if (func_80A23A74(arg0, arg1) != 0) {
        func_80A23530(arg0, &D_80A25658);
    }
}
