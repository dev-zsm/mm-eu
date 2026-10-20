// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern void func_800854D8(void);
extern void func_80085550(void);

void func_800855A8(s32 arg0) {
    if (arg0 == 0) {
        func_80085550();
    } else {
        func_800854D8();
    }
}

