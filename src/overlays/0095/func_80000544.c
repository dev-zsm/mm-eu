#include "types.h"

extern void func_800B6490();
extern u8 D_801E7E1F;

void func_80000544(void *a0, s32 a1) {
    if (D_801E7E1F & 0x80) {
        func_800B6490(a0);
    }
}
