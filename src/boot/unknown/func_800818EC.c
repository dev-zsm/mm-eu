#include "types.h"

extern void func_80081880(void);
extern void func_80081A50(void *a0, void *a1, s32 a2, s32 a3);
extern u8 D_8009C208[];

void func_800818EC(void) {
    func_80081A50(D_8009C208, func_80081880, 0, 0);
}

