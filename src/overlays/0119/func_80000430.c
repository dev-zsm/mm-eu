#include "types.h"

extern void *D_808E0BA8[];

void func_80000430(void *a0) {
    ((void (*)(void *))D_808E0BA8[*(s32 *)((u8 *)a0 + 0x164)])(a0);
}
