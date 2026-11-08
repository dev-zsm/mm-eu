#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0489.h"
extern u8 D_600A174[];
extern u8 D_80B30D88[];
extern f32 D_80B33D34;
void func_80137934(u8 *a, u8 *b, f32 c);

void func_8000864C(Actor *thisx) {
    M2C_FIELD(thisx, f32 *, 0x354) = D_80B33D34;
    M2C_FIELD(thisx, s16 *, 0x350) = 0x7D0;
    func_80137934((u8 *)thisx + 0x144, D_600A174, -6.0f);
    M2C_FIELD(thisx, s16 *, 0x370) = 0;
    M2C_FIELD(thisx, void **, 0x2EC) = D_80B30D88;
}
