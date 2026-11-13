#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0076.h"

M2C_UNK func_80137828(s32, M2C_UNK *, M2C_UNK);     /* extern */
M2C_UNK func_8089A490(u8 *);                      /* extern */
extern M2C_UNK D_6001CCC;
extern M2C_UNK D_8089B7FC;

void func_80001944(u8 *arg0, s32 arg1) {
    if (arg1 == 0) {
        func_80137828(arg0 + 0x144, &D_6001CCC, 0x40000000);
        func_8089A490(arg0);
    } else {
        func_80137828(arg0 + 0x144, &D_6001CCC, 0xBF800000);
        if ((arg1 == 2) || (arg1 == 3)) {
            M2C_FIELD(arg0, u8 *, 0x375) = (u8) (M2C_FIELD(arg0, u8 *, 0x375) & 0xFFFE);
            func_8089A490(arg0);
        }
    }
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    M2C_FIELD(arg0, s16 *, 0x290) = (s16) arg1;
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
    M2C_FIELD(arg0, M2C_UNK **, 0x284) = &D_8089B7FC;
}
