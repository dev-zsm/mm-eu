// FLAGS: -O2 -g0
#include "types.h"
extern u8 D_8009D130;
void func_8008F3E0(s32 a, void *b, s32 c);
void func_800871D0(s32 arg0) {
    func_8008F3E0(arg0 + 8, &D_8009D130, 1);
}
