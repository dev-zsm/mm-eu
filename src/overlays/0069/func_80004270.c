#include "types.h"
typedef struct { u8 pad[0x1BC]; f32 a; } A;
extern void func_8087F0E4(A *x);
void func_80004270(A *x) { x->a = 0.0f; func_8087F0E4(x); }
