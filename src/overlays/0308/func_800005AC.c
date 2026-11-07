#include "types.h"
#include "m2c_compat.h"
extern u8 D_80A11818[];
extern u8 D_80A10F38[];
void func_800B8C4C(u8 *a, s32 b);
void func_800BD9E0(u8 *a, u8 *b, s32 c);

void func_800005AC(u8 *a) {
    s16 v;

    func_800B8C4C(a, 0x387C);
    func_800BD9E0(a + 0x144, D_80A11818, 0);
    v = M2C_FIELD(a, s16 *, 0x92);
    M2C_FIELD(a, void **, 0x188) = D_80A10F38;
    M2C_FIELD(a, s16 *, 0xBE) = v;
    M2C_FIELD(a, s16 *, 0x32) = v;
}
