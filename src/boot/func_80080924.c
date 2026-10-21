// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern s32 func_8008EFD0(void);

// Thin wrapper around func_8008EFD0, return value discarded. SDK name unknown.
void func_80080924(void) {
    func_8008EFD0();
}
