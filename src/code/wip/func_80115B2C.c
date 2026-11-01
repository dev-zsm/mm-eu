#include "types.h"
typedef struct { u8 pad0[0x34]; s16 max; s16 cur; u8 pad38[10]; u8 flag; } Gauge;
extern Gauge D_801E6EF0;
extern void Audio_PlaySfx(u16);

s32 func_80115B2C(s32 unused, s16 amount) {
    if (amount > 0) {
        Audio_PlaySfx(0x480B);
    } else if (D_801E6EF0.flag != 0 && amount < 0) {
        amount >>= 1;
    }
    D_801E6EF0.cur += amount;
    if (D_801E6EF0.cur > D_801E6EF0.max) {
        D_801E6EF0.cur = D_801E6EF0.max;
    }
    if (D_801E6EF0.cur > 0) { return 1; }
    D_801E6EF0.cur = 0;
    return 0;
}
