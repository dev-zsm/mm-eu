#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0318.h"
extern u8 D_600466C[];
extern u8 D_80A1B0A0[];
void func_80137884(u8 *a, u8 *b, f32 c);
void func_800B6564(u8 *a, f32 b);

void func_80000308(Actor *thisx) {
    func_80137884((u8 *)thisx + 0x144, D_600466C, 0.0f);
    M2C_FIELD(thisx, s32 *, 0x13C) = 0;
    func_800B6564(thisx, 0.01f);
    M2C_FIELD(thisx, void **, 0x188) = D_80A1B0A0;
}
