#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0616.h"
extern u8 D_80BE90F4[];
void func_80BE85C4(u8 *a, s32 b, f32 c);

void func_80000DC8(u8 *a) {
    if (M2C_FIELD(a, s32 *, 0x2C4) != 6) {
        func_80BE85C4(a, 6, 1.0f);
    }
    M2C_FIELD(a, s16 *, 0x116) = 0x72D;
    M2C_FIELD(a, s16 *, 0x28E) = 0x1F40;
    M2C_FIELD(a, s16 *, 0x2C0) = 2;
    M2C_FIELD(a, void **, 0x284) = D_80BE90F4;
}
