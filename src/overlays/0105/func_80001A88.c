// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137934(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
M2C_UNK func_808C4BC0(u8 *);                      /* extern */
extern M2C_UNK D_600B508;
extern M2C_UNK D_808C5FFC;
extern M2C_UNK D_808C6180;

void func_80001A88(u8 *arg0) {
    if (&D_808C5FFC != M2C_FIELD(arg0, M2C_UNK **, 0x188)) {
        func_80137934(arg0 + 0x144, &D_600B508, 0xC0400000, arg0);
        M2C_FIELD(arg0, s8 *, 0x190) = -3;
        M2C_FIELD(arg0, s16 *, 0x2EE) = 0;
        M2C_FIELD(arg0, s16 *, 0x2EC) = -1;
        M2C_FIELD(arg0, s8 *, 0x18C) = 1;
        M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    } else {
        M2C_FIELD(arg0, s16 *, 0x2EE) = 0xA;
        M2C_FIELD(arg0, s16 *, 0x2EC) = 9;
        M2C_FIELD(arg0, f32 *, 0x70) = 10.0f;
    }
    func_808C4BC0(arg0);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808C6180;
}
