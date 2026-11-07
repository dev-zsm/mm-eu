#include "types.h"
#include "m2c_compat.h"
extern u16 D_80B0CA40[];
void func_80151DF4(u8 *a, s32 b);

void func_80000C74(u8 *a, u8 *play) {
    func_80151DF4(play, D_80B0CA40[M2C_FIELD(a, s16 *, 0x284)]);
    M2C_FIELD(a, s16 *, 0x288) = ((s16 *)D_80B0CA40)[M2C_FIELD(a, s16 *, 0x284)];
}
