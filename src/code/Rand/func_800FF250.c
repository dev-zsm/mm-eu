#include "types.h"

f32 func_8008704C(void);
s16 Rand_S16Offset(s16 base, s16 range) {
    return ((((s32) (func_8008704C() * range)) & 0xFFFFu) & 0xFFFFu) + base;
}
