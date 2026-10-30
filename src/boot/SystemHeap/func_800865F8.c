// FLAGS: -O2 -g0
#include "systemheap.h"

void SystemHeap_RunInits(void) {
    SystemHeapInitEntry *entry;
    SystemHeapInitEntry *prev;
    s32 off;
    void (*fn)(void);

    off = D_800976A0;
    entry = (SystemHeapInitEntry *)&D_800976A0;
    prev = NULL;
    while (off != 0) {
        entry = (SystemHeapInitEntry *)((u8 *)entry + off);
        fn = entry->fn;
        if (fn != NULL) {
            fn();
        }
        off = entry->next;
        entry->next = (s32)prev;
        prev = entry;
    }
    D_800976A0 = (s32)prev;
}
