// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_8093FB5C(u8 *);                      /* extern */
M2C_UNK func_8093FC48(u8 *);                      /* extern */
M2C_UNK func_8093FF70(u8 *, s32);                 /* extern */
extern M2C_UNK D_8094025C;

void func_80001450(u8 *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, f32 *, 0x1A8) >= 18.0f) {
        func_800FFCBC(arg0 + 0x32, M2C_FIELD(arg0, s16 *, 0x3EC), 2, 0x200, 0x80);
        M2C_FIELD(arg0, s16 *, 0xBE) = (s16) M2C_FIELD(arg0, s16 *, 0x32);
    }
    func_8093FB5C(arg0);
    if (M2C_FIELD(arg0, s16 *, 0x3EC) == M2C_FIELD(arg0, s16 *, 0xBE)) {
        M2C_FIELD(arg0, M2C_UNK **, 0x410) = &D_8094025C;
    }
    func_8093FC48(arg0);
    func_8093FF70(arg0, arg1);
}
