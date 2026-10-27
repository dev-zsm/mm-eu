#include "types.h"

void CutsceneFlags_Set(void *ctx, s16 flag) {
    s16 index = flag / 16;
    s16 bit = flag % 16;
    int new_var;
    u16 *flags = (u16 *) (((u8 *) ctx) + 0x18B20);
    bit = 1 << bit;
    new_var = bit;
    flags[index] = flags[index] | new_var;
}
