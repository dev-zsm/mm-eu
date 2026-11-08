// FLAGS: -O2 -g3 -mips2
#include "types.h"

void func_800B8BDC();

typedef struct {
    u8 pad[0x14B];
    u8 f;
} T0056;

void func_800030A8(T0056 *arg0) {
    s32 v0;
    s32 v1;

    if (arg0->f == 1) {
        v0 = 0x8E7;
    } else {
        if (arg0->f == 3) {
            v1 = 0x834;
        } else {
            v1 = 0x1826;
        }
        v0 = v1;
    }
    func_800B8BDC(arg0, v0 & 0xFFFF);
}
