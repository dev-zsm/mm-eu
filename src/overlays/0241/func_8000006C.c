#include "types.h"
typedef struct { u8 r, g, b; } C3;
extern C3 D_8097F138[];
void func_8000006C(s32 i, C3 *dst) {
    *dst = D_8097F138[i];
}
