#include "types.h"
typedef struct { u8 p[0x1E0]; s8 g; u8 q[3]; s32 f; } B;
typedef struct { u8 p[0x34C]; B *b; } A;
s32 func_800018B8(A *this) { B *b; if (this->b != 0) { b = this->b; if (b->f == 2) { b->g++; return 1; } } return 0; }
