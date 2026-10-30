#include "types.h"
typedef struct { u8 p[0x1D4]; void *x; } A;
extern u8 D_80AE43D0[];
extern void func_80137070();
void func_8000201C(A *a, s32 b) {
    if (a->x != D_80AE43D0) {
        func_80137070((u8 *)a + 0x190, a);
    }
}
