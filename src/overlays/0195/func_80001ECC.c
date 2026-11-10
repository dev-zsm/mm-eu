#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80958E58(u8 *);                      /* extern */
M2C_UNK func_80958F60(u8 *);                      /* extern */
extern M2C_UNK D_6005210;
extern M2C_UNK D_6005850;
extern M2C_UNK D_6005F78;

s32 func_80001ECC(s32 arg0, s32 arg1, M2C_UNK **arg2, M2C_UNK arg3, s32 arg4, u8 *arg5) {
    s16 temp_v0;

    switch (arg1) {                                 /* irregular */
        case 1:
            temp_v0 = M2C_FIELD(arg5, s16 *, 0x522);
            if ((temp_v0 != 0) && (M2C_FIELD(arg5, s16 *, 0x52E) == 0)) {
            if (temp_v0 >= 2) {
                func_80958E58(arg5);
            } else {
                func_80958F60(arg5);
            }
            }
            break;
        case 4:
            if (M2C_FIELD(arg5, u16 *, 0x5C2) & 0x20) {
            *arg2 = &D_6005850;
            }
            break;
        case 5:
            if (M2C_FIELD(arg5, u16 *, 0x5C2) & 0x20) {
            *arg2 = &D_6005210;
            }
            break;
        case 8:
            if (M2C_FIELD(arg5, u16 *, 0x5C2) & 0x20) {
            *arg2 = &D_6005F78;
            }
            break;
    }
    return 0;
}
