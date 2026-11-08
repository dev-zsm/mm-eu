#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0559.h"
extern u8 D_80BAB5A8[];
extern u8 D_80BAA470[];
void func_800B8C4C(u8 *a, s32 b);
void func_800BD9E0(u8 *a, u8 *b, s32 c);

void func_80000750(Actor *thisx) {
    M2C_FIELD(thisx, s16 *, 0x32E) = 0;
    func_800B8C4C(thisx, 0x3A61);
    func_800BD9E0((u8 *)thisx + 0x1F0, D_80BAB5A8, 3);
    M2C_FIELD(thisx, void **, 0x234) = D_80BAA470;
}
