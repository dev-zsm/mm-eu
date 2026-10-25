#include "types.h"

typedef struct {
    u8 *startAddr;
    u8 *curAddr;
    u32 size;
    s32 count;
} AudioAllocPool;
void *AudioHeap_Alloc(AudioAllocPool *pool, u32 size) {
    u8 *ret;
    u32 aligned = (size + 0xF) & (~0xF);
    u8 *new_var;
    new_var = pool->curAddr;
    if ((pool->startAddr + pool->size) >= (new_var + aligned)) {
        ret = new_var;
        pool->curAddr += aligned;
    } else {
        return (void *) 0;
    }
    pool->count++;
    return ret;
}
