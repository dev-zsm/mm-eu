#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0583.h"
extern u8 D_80BC0058[];
void func_80BBFF54(u8 *a, s32 b);

void func_80000228(u8 *a) {
    M2C_FIELD(a, s16 *, 0x116) = 0x234;
    M2C_FIELD(a, f32 *, 0x228) = 1600.0f;
    M2C_FIELD(a, f32 *, 0xC4) = 1600.0f;
    func_80BBFF54(a, 1);
    M2C_FIELD(a, s16 *, 0x21A) = 0;
    M2C_FIELD(a, void **, 0x200) = D_80BC0058;
}
