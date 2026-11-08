#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0489.h"
extern u8 D_6009E58[];
extern u8 D_80B2F54C[];
extern f32 D_80B33CD8;
void func_80137934(u8 *a, u8 *b, f32 c);

void func_80006E10(u8 *a) {
    M2C_FIELD(a, f32 *, 0x354) = D_80B33CD8;
    M2C_FIELD(a, s16 *, 0x350) = 0x7D0;
    M2C_FIELD(a, s16 *, 0x370) = 0;
    func_80137934(a + 0x144, D_6009E58, 0.0f);
    M2C_FIELD(a, void **, 0x2EC) = D_80B2F54C;
}
