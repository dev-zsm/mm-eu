#include "types.h"

typedef struct { u8 pad0[0x144]; void (*unk144)(); } A;
extern s32 func_8095398C();

void func_8000040C(A *a, s32 b) {
    if (func_8095398C(a, b) == 0) {
        a->unk144(a, b);
    }
}
