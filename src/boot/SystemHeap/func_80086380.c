// FLAGS: -O2 -g0
#include "systemheap.h"

void SystemHeap_Free(void *ptr) {
    if (ptr != NULL) {
        Arena_Free(&D_8009D0F0, ptr);
    }
}
