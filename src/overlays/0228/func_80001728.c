#include "types.h"
#include "m2c_compat.h"

f32 func_8017A844(f32);                         /* extern */
M2C_UNK func_80968AFC(u8 *, s32);                 /* extern */
extern M2C_UNK D_80969DC8;

void func_80001728(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, f32 *, 0x74) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x68) = -50.0f;
    M2C_FIELD(arg0, s16 *, 0x14A) = (s16) (s32) func_8017A844(25.0f);
    func_80968AFC(arg0, arg1);
    M2C_FIELD(arg0, s16 *, 0x1C) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80969DC8;
}
