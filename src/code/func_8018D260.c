// FLAGS: -O2 -g0 -mips2
#include "types.h"

void *AudioHeap_SearchPermanentCache(s32 arg0, s32 arg1);
void *AudioHeap_SearchRegularCaches(s32 arg0, s32 arg1, s32 arg2);

void *AudioHeap_SearchCaches(s32 arg0, s32 arg1, s32 arg2) {
    void *cache = AudioHeap_SearchPermanentCache(arg0, arg2);

    if (cache != NULL) {
        return cache;
    }
    if (arg1 == 3) {
        return NULL;
    }
    return AudioHeap_SearchRegularCaches(arg0, arg1, arg2);
}
