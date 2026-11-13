#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0110.h"

M2C_UNK func_80137788(s32, M2C_UNK *, M2C_UNK, f32, f32, s32, f32); /* extern */
extern M2C_UNK D_60019CC;
extern M2C_UNK D_808D1BC0;

void func_80001E04(u8 *arg0) {
    func_80137788(arg0 + 0x144, &D_60019CC, 0x40000000, 0.0f, 41.0f, 2, 0.0f);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808D1BC0;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
}
