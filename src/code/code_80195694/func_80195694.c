// FLAGS: -O2 -g0 -mips2
#include "types.h"
extern u8 D_801CE958[];
extern u8 D_801CE9C8[];
extern u8 *D_801CEAB8;
extern u8 *D_801CEABC;
void func_80195694(s32 arg0) {
    D_801CEAB8 = D_801CE9C8 + arg0 * 0x22;
    D_801CEABC = D_801CE958 + arg0 * 0x10;
}
