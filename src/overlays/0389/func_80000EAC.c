#include "types.h"
void func_80000EAC(u8 *a0, s32 a1) {
    if (*(s16 *)(a0 + 0xBC) < 0x4000) {
        *(s16 *)(a0 + 0xBC) += 0x28;
    }
}
