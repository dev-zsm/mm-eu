// FLAGS: -O2 -g3
#include "os_internal.h"

void func_80081920(void) {
    Fault_RemoveClient(&D_8009C208);
}
