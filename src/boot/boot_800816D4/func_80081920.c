// FLAGS: -O2 -g3
#include "types.h"

extern void Fault_RemoveClient(void *a);
extern u8 D_8009C208[];

void func_80081920(void) {
    Fault_RemoveClient(D_8009C208);
}
