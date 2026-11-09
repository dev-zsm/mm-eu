#include "types.h"
typedef struct { u8 p0[0x1681C]; s32 a; u8 p1[0x1682E-0x16820]; s8 b; } G;
s32 func_8013E684(s32, s32, s32, s32);
void func_80A7C71C(s32, G *);
void func_80003010(s32 arg0, G *arg1) {
    if (func_8013E684(arg0, 0, -1, 0) != 0) {
        arg1->b = 0;
        arg1->a = 0;
        func_80A7C71C(arg0, arg1);
    }
}
