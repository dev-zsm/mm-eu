// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct { u8 pad0[0x1E0]; s8 c; u8 pad1[3]; s32 k; } T;
typedef struct { u8 pad[0x34C]; T *t; } S;

s32 func_800018B8(S *s) {
    T *t = s->t;
    if (t != 0) {
        if (t->k == 2) {
            t->c++;
            return 1;
        }
    }
    return 0;
}
