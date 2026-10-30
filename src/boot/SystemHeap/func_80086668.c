// FLAGS: -O2 -g0
#include "systemheap.h"

void SystemHeap_Init(void *start, size_t size) {
    MallocInit(start, size);
    SystemHeap_RunInits();
}
