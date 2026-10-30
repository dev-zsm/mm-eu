#include "types.h"
extern void func_800B6490();
typedef struct { u8 pad0[0x120]; s32 x; } B;
typedef struct { u8 pad0[0x124]; B *p; } A;
void func_8000026C(A *a, s32 b) {
    A *s = a;
    if (s->p != 0) {
        s->p->x = 0;
    }
    func_800B6490(s->p);
}
