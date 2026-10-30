#include "types.h"
extern u8 D_8085C05C[];
extern s32 D_8085C028[];
void func_8082D8D4();
void func_80001414(s32 a0, s32 a1) {
    u8 i = D_8085C05C[a1];
    if (i != 0) {
        func_8082D8D4(a0, D_8085C028[i]);
    }
}
