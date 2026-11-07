#include "types.h"
#include "m2c_compat.h"
extern void (*D_80B3393C[])(u8 *, u8 *);

void func_80002208(u8 *a) {
    u8 *p = M2C_FIELD(a, u8 **, 0);

    if (p != NULL && M2C_FIELD(a, u8 **, 8) != NULL) {
        D_80B3393C[M2C_FIELD(a, s8 *, 4)](a, p);
    }
}
