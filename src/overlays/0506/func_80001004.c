#include "types.h"
typedef struct B { u8 p0[0x198]; s16 x; } B;
typedef struct { u8 p0[0x120]; s32 a; u8 p1[0x22C-0x124]; B *b; } A;
void func_80B55A54(A *);
void func_80B56640(A *);
void func_80001004(A *this) { B *t; func_80B55A54(this); if (this->a == 0 && this->b != 0) { t = this->b; t->x = 1; } func_80B56640(this); }
