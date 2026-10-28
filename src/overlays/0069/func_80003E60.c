#include "types.h"

extern void func_8087ECD4(u8 *);

void func_80003E60(u8 *a0) {
    *(s32 *)(a0 + 0x148) = 0;
    *(s32 *)(a0 + 0x14C) = 0;
    func_8087ECD4(a0);
}
