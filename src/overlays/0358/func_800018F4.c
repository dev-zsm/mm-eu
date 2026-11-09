#include "types.h"
typedef struct { u8 p[0x1E4]; s32 f; } B;
typedef struct { u8 p[0x34C]; B *b; } A;
s32 func_800018F4(A *this) { B *b; if (this->b != 0) { b = this->b; if (b->f == 2 || b->f == 1) { b->f = 4; return 1; } } return 0; }
