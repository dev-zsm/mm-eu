#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0318.h"
extern u8 D_600466C[];
extern u8 D_80A1AFF8[];
void func_80137884(u8 *a, u8 *b, f32 c, u8 *d);

void func_80000270(Actor *thisx) {
    func_80137884((u8 *)thisx + 0x144, D_600466C, 0.0f, thisx);
    M2C_FIELD(thisx, s32 *, 0x13C) = 0;
    M2C_FIELD(thisx, void **, 0x188) = D_80A1AFF8;
}
