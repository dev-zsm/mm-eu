#include "types.h"

typedef struct N { s16 u0; u8 p[0x12A]; struct N *u12C; } N;
typedef struct { u8 p[0x1CE4]; N *u1CE4; } A;

N *func_800003FC(A *a) {
    N *n = a->u1CE4;
    while (n != 0) {
        if (n->u0 == 0x1F6) {
            return n;
        }
        n = n->u12C;
    }
    return 0;
}
