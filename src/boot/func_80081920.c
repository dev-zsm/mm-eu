// FLAGS: -O2 -g3
#include "types.h"

extern void func_80081B34(void *a);
extern u8 D_8009C208[];

void func_80081920(void) {
    func_80081B34(D_8009C208);
}
