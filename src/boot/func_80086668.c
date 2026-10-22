// FLAGS: -O2 -g0
#include "types.h"
void MallocInit(void);
void SystemHeap_RunInits(void);
void SystemHeap_Init(void) {
    MallocInit();
    SystemHeap_RunInits();
}
