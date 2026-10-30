#include "types.h"
extern void func_800F1D6C(s16);
typedef struct { u8 pad0[0xA86]; s8 v; } A;
void func_8000ACF8(A *a) {
    if (a->v >= 0) {
        func_800F1D6C(a->v);
        a->v = -1;
    }
}
