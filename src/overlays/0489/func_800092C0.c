#include "types.h"
#include "m2c_compat.h"
extern u8 D_6009E58[];
extern u8 D_80B319FC[];
extern f32 D_80B33D70;
void func_80137934(u8 *a, u8 *b, f32 c);

void func_800092C0(u8 *a) {
    M2C_FIELD(a, f32 *, 0x354) = D_80B33D70;
    M2C_FIELD(a, s16 *, 0x350) = 0x7D0;
    func_80137934(a + 0x144, D_6009E58, -10.0f);
    M2C_FIELD(a, s16 *, 0x370) = 0;
    M2C_FIELD(a, void **, 0x2EC) = D_80B319FC;
}
