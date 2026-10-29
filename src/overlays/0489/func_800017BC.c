#include "types.h"

typedef struct {
    u8 pad0[0x28];
    f32 a;
    u8 pad1[0x88 - 0x2C];
    f32 b;
} T;

extern f32 D_80B33BA0;

s32 func_800017BC(T *p) {
    if (D_80B33BA0 < p->b) {
        p->a = p->b;
        return 1;
    }
    return 0;
}
