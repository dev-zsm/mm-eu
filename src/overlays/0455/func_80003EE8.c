#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0455.h"

M2C_UNK func_80137788(s32, M2C_UNK *, M2C_UNK, f32, f32, s32, f32); /* extern */
extern M2C_UNK D_6016028;
extern M2C_UNK D_80AEDF08;

void func_80003EE8(u8 *arg0) {
    func_80137788(arg0 + 0x144, &D_6016028, 0x3FC00000, 0.0f, 0.0f, 0, -3.0f);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80AEDF08;
}
