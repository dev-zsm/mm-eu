#include "types.h"
typedef struct { u8 pad0[0xA70]; u32 a70; } P;
s32 func_80136480();
void func_8002D038(s32 a, P *p, s32 c) {
    if (func_80136480(a, (u8 *)p + 0x240) != 0) {
        p->a70 |= 0x1000000;
    }
}
