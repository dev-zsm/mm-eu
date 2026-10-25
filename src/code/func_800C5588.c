#include "types.h"

extern s32 BgCheck_AnyLineTest2(void *a0, void *a1, void *a2, void *a3, void *a4, s32 a5, s32 a6, s32 a7, void *a8);

s32 BgCheck_AnyLineTest1(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5) {
    return BgCheck_AnyLineTest2(a0, a1, a2, a3, a4, 1, 1, 1, a5);
}
