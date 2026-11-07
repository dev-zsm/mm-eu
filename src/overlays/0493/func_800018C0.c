#include "types.h"
#include "m2c_compat.h"
extern u8 D_80B4191C[];
void func_800B8284(u8 *a, u8 *b, s32 c, s32 d, s32 e);

void func_800018C0(u8 *a, u8 *play) {
    M2C_FIELD(a, u32 *, 4) |= 0x10000;
    func_800B8284(a, play, M2C_FIELD(a, s32 *, 0x98), M2C_FIELD(a, s32 *, 0x9C), 0);
    M2C_FIELD(a, void **, 0x144) = D_80B4191C;
}
