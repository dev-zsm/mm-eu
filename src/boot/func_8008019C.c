// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern u8 D_80000500[];
extern u8 D_8009B610[];
extern s32 D_80096CCC;

void func_80080180(u8 *p, s32 n, u32 v);
void osViSetMode(u8 *p);
void osViSetSpecialFeatures(s32 a);
void osViSwapBuffer(u8 *p);
void osViBlack(s32 a);

void func_8008019C(void) {
    func_80080180(D_80000500, 0x25800, 0x10001);
    osViSetMode(D_8009B610);
    osViSetSpecialFeatures(D_80096CCC);
    osViSwapBuffer(D_80000500);
    osViBlack(0);
}
