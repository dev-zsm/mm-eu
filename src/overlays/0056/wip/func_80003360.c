#include "types.h"

typedef struct { u8 pad0[0xA74]; u32 unkA74; } A;
extern void func_8082F97C();

s32 func_80003360(A *a) {
    if (a->unkA74 & 0x40000000) {
        func_8082F97C();
        return 1;
    } else {
        return 0;
    }
}
