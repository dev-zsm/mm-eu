#include "types.h"

extern void func_8095E978();
extern u8 D_40367B0;

void func_80000318(void *a0, s32 a1, u8 *a2) {
    if (*(s16 *)(a2 + 0x56) == 0) {
        func_8095E978(a0, a2, &D_40367B0);
    }
}
