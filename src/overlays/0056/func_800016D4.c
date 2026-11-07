#include "types.h"
typedef struct { u8 pad0[0x14B]; u8 a14B; u8 pad1[0x920]; u32 a6c; } P;
extern u16 *D_80862264;
void func_800016D4(P *p, u16 b) {
    if (p->a14B == 2 && ~(*D_80862264 | ~b) == 0) {
        p->a6c |= 0x10;
    }
}
