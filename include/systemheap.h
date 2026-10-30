#ifndef SYSTEMHEAP_H
#define SYSTEMHEAP_H

#include "types.h"
#include "libc.h"

/* Entry of the list of initialisers run at boot. `next` is a byte offset from the entry itself until
 * SystemHeap_RunInits relinks the list in reverse order, then it holds the address of the previous entry. */
typedef struct SystemHeapInitEntry {
    /* 0x0 */ s32 next;
    /* 0x4 */ void (*fn)(void);
} SystemHeapInitEntry;

extern s32 D_800976A0; /* head word of the list of initialisers */

void *SystemHeap_Malloc(size_t size);
void SystemHeap_Free(void *ptr);
void SystemHeap_RunBlockFunc(void *blocks, u32 count, u32 size, void (*fn)(void *));
void SystemHeap_RunBlockFunc1(void *blocks, u32 count, u32 size, void (*fn)(void *, s32));
void SystemHeap_RunBlockFunc1Reverse(void *blocks, u32 count, u32 size, void (*fn)(void *, s32), s32 freeBlocks);
void SystemHeap_RunInits(void);
void SystemHeap_Init(void *start, size_t size);

#endif
