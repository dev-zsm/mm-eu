#ifndef ARENA_H
#define ARENA_H

#include "ultra64.h"
#include "libc.h"

#define ARENA_NODE_MAGIC 0x7373
#define ARENA_NODE_SIZE 0x10

/* Header placed right before every payload of the heap. */
typedef struct ArenaNode {
    /* 0x00 */ s16 magic;
    /* 0x02 */ s16 isFree;
    /* 0x04 */ u32 size; /* payload size, header excluded */
    /* 0x08 */ struct ArenaNode *next;
    /* 0x0C */ struct ArenaNode *prev;
} ArenaNode; /* 0x10 */

struct Arena {
    /* 0x00 */ ArenaNode *head;
    /* 0x04 */ void *start;
    /* 0x08 */ OSMesgQueue lock;
    /* 0x20 */ u8 unk20;
    /* 0x21 */ u8 isInit;
    /* 0x22 */ u8 pad22[2];
}; /* 0x24 */

extern OSMesg D_8009D130[1]; /* message buffer of the lock queue */

void ArenaImpl_LockInit(Arena *arena);
void ArenaImpl_Lock(Arena *arena);
void ArenaImpl_Unlock(Arena *arena);
ArenaNode *ArenaImpl_GetLastBlock(Arena *arena);
void *func_80087394(Arena *arena, size_t size);       /* first fit, scanning from the head */
void func_80087560(Arena *arena, void *ptr);          /* free and merge with the free neighbours */
void __osMallocAddHeap(Arena *arena, void *start, size_t size);

#endif
