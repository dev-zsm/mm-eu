#include "types.h"
typedef struct { u8 p[0x1E4]; s32 f; } B;
typedef struct { u8 p[0x34C]; B *b; } A;
s32 func_80001884(A *this) { B *b; if (this->b != 0) { b = this->b; if (b->f == 0) { b->f = 1; return 1; } } return 0; }
