// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern u8 D_8009BDE8[];
extern s32 D_8009C1E8;
extern s32 D_8009C1EC;
extern u32 D_8009C1F0;
extern s32 D_8009C1F4;

void func_800807E0(s32 a, void *b, u32 c, u32 *d);

void *func_80080E80(void) {
    u32 temp_v1;
    u32 var_a2;

    D_8009C1F4 = D_8009C1E8 - 0x19;
    temp_v1 = D_8009C1E8 - (u32)D_8009BDE8;
    if (D_8009C1F0 < temp_v1) {
        var_a2 = D_8009C1F0;
    } else {
        var_a2 = temp_v1;
    }
    func_800807E0(D_8009C1EC, D_8009BDE8, var_a2, &D_8009C1F0);
    D_8009C1EC += var_a2;
    D_8009C1F0 -= var_a2;
    return D_8009BDE8;
}
