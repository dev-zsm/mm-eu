// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801378E0(s32, M2C_UNK *, u8 *);      /* extern */
extern M2C_UNK D_6004210;
extern M2C_UNK D_80A0CFF8;
extern M2C_UNK D_80A0E208;

void func_80000D54(u8 *arg0) {
    func_801378E0(arg0 + 0x144, &D_6004210, arg0);
    M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80A0E208;
    M2C_FIELD(arg0, s16 *, 0x29E) = 0x14;
    M2C_FIELD(arg0, M2C_UNK **, 0x298) = &D_80A0CFF8;
}
