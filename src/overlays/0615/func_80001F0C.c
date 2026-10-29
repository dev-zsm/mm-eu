#include "types.h"
typedef struct { u8 pad[0x118]; s16 unk118; } B;
typedef struct { u8 pad[0x1CCC]; B *unk1CCC; } A;
B *func_80001F0C(s32 a0, A *a1) { B *b = a1->unk1CCC; b->unk118 = 3; return b; }
