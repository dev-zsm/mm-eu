// FLAGS: -O2 -g0 -mips2
#include "types.h"
extern u8 D_801F4D73[];
extern s32 func_8019C418();
u8 func_8019C49C(void) {
    return D_801F4D73[func_8019C418() * 4];
}
