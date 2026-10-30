#include "types.h"
typedef struct { u8 p0[0x384]; s16 a; u8 p1[0xA6C-0x386]; s32 f; u8 p2[0xB2A-0xA70]; u8 b; } C;
extern s32 func_8016A844();
extern void func_800DFFF8();
void func_8001A804(s32 a, C *c) {
    c->b = 0;
    c->f &= ~0xC00;
    c->a = 0;
    func_800DFFF8(func_8016A844(a, 0));
}
