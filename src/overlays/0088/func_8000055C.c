#include "types.h"
typedef struct { u8 pad0[0xC]; u16 c; } P;
extern void func_808A7C20();
s32 func_8000055C(s32 a, s32 b, P *c) {
    if (~(c->c | ~0x4000) == 0) {
        func_808A7C20(b, a);
        return 1;
    }
    return 0;
}
