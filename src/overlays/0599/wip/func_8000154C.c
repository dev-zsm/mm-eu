#include "types.h"
typedef struct { u8 pad[0x286]; s16 x286; } A;
typedef struct { u8 pad[2]; s16 x2; } B;
s32 func_8000154C(s32 a0, s32 a1, s32 a2, s32 a3, B *a4, A *a5) {
if (a1 == 0xC) { a4->x2 = a4->x2 + (s16)(-a5->x286); }
return 0;
}
