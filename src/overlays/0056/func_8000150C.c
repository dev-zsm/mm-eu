#include "types.h"
typedef struct { u8 pad0[0x14F]; u8 a14F; } P;
s32 func_8082E5D0();
extern u8 D_400D488[];
extern void *D_8085B5D4[];
void *func_8000150C(P *p) {
    if (func_8082E5D0(p) != 0) {
        return D_400D488;
    }
    return D_8085B5D4[p->a14F];
}
