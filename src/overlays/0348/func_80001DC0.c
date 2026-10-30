#include "types.h"

typedef struct { u8 p0[4]; f32 u4; } B;
typedef struct { u8 p0[0x25C]; f32 u25C; } C;

s32 func_80001DC0(s32 a0, s32 a1, s32 *a2, B *a3, s32 a4, C *a5) {
    if (a1 == 1) {
        a3->u4 = a3->u4 - a5->u25C;
    }
    if (a1 == 5) {
        *a2 = 0;
    }
    return 0;
}
