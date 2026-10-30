#include "types.h"
typedef struct { u8 pad[2]; s16 v; } B;
typedef struct { u8 pad[0x17D8]; s16 v; } C;
s32 func_8000ACF8(s32 a0, s32 a1, s32 a2, s32 a3, B *a4, C *a5) {
    if (a1 == 0x18) {
        a4->v += a5->v;
    }
    return 0;
}
