#include "types.h"

typedef struct {
    s16 id;
    u8 pad0[0x12C - 2];
    void *q;
} A;

typedef struct {
    u8 pad0[0x1D08];
    A *a;
} T;

void *func_800000E4(T *p) {
    A *a = p->a;
    if (a != 0) {
        if (a->id != 0x1D6) {
            a = a->q;
        }
        return a;
    }
    return 0;
}
