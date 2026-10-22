// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern s32 osEPiStartDma(void);

// Thin wrapper around osEPiStartDma, return value discarded. SDK name unknown.
void func_80080924(void) {
    osEPiStartDma();
}
