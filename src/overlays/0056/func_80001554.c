#include "types.h"
typedef struct { u8 pad0[0x14F]; u8 a14F; } P;
s32 func_800B6EAC();
extern u8 D_400D520[];
extern void *D_8085B784[];
void *func_80001554(P *p) {
    if (func_800B6EAC(p) != 0) {
        return D_400D520;
    }
    return D_8085B784[p->a14F];
}
