// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} V0069;

void func_80182B28();
extern V0069 D_80888934;

s32 func_8000D5E8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u8 *arg5) {
    V0069 v = D_80888934;

    if (arg1 == 3) {
        func_80182B28(&v, arg5 + 0x258);
    }
    return 0;
}
