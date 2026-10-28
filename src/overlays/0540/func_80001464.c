// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B5B20(u8 *, s32);                     /* extern */
M2C_UNK func_800B5B64(u8 *, s32);                 /* extern */
M2C_UNK func_80137828(u8 *, M2C_UNK *, M2C_UNK);  /* extern */
s32 func_80B88E74(u8 *, u8 *);                  /* extern */
extern M2C_UNK D_60028B8;

s32 func_80001464(u8 *arg0, u8 *arg1) {
    u8 *sp24;

    if (func_80B88E74(arg0, arg1) != 0) {
        sp24 = M2C_FIELD(arg1, u8 **, 0x1CCC);
        func_80137828(arg0 + 0x144, &D_60028B8, 0xC0800000);
        if (M2C_FIELD(sp24, u8 *, 0x14B) == 2) {
            if (func_800B5B20(arg1, M2C_FIELD(arg0, s16 *, 0x1C) & 0x7F) == 0) {
                func_800B5B64(arg1, M2C_FIELD(arg0, s16 *, 0x1C) & 0x7F);
                return 1;
            }
            return 3;
        }
        if (func_800B5B20(arg1, ((s16) M2C_FIELD(arg0, s16 *, 0x1C) >> 7) & 0x7F) == 0) {
            func_800B5B64(arg1, ((s16) M2C_FIELD(arg0, s16 *, 0x1C) >> 7) & 0x7F);
            return 4;
        }
        return 7;
    }
    return 0;
}
