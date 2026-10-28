// FLAGS: -O2 -g0
#include "types.h"
extern void func_8008738C(void *p);
extern u8 D_8009D0F0[];

void MallocIsInitialized(void) {
    func_8008738C(D_8009D0F0);
}
