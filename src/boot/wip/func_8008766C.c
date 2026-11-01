// FLAGS: -O2 -g3
#include "types.h"

typedef struct ArenaNode {
    s16 magic;
    s16 isFree;
    u32 size;
    struct ArenaNode *next;
    struct ArenaNode *prev;
} ArenaNode;

void ArenaImpl_Lock(s32 arena);
void ArenaImpl_Unlock(s32 arena);
void *func_80087394(s32 arena, u32 size);
void Arena_Free(s32 arena, void *ptr);
void func_80087560(s32 arena, void *ptr);
void bcopy(void *src, void *dst, u32 n);
void func_80096AD0(void *a0, void *a1, s32 a2, u32 a3);

void *func_8008766C(s32 arena, void *ptr, u32 size) {
    ArenaNode *node;
    ArenaNode *next;
    ArenaNode *newNext;
    ArenaNode overNext;
    void *newPtr;
    u32 oldSize;
    u32 diff;

    size = (size + 0xF) & ~0xF;
    ArenaImpl_Lock(arena);
    if (ptr == NULL) {
        ptr = func_80087394(arena, size);
    } else if (size == 0) {
        Arena_Free(arena, ptr);
        ptr = NULL;
    } else {
        oldSize = ((ArenaNode *)ptr)[-1].size;
        node = (ArenaNode *)ptr - 1;
        if (size == oldSize) {
        } else if (oldSize < size) {
            next = node->next;
            diff = size - oldSize;
            if (next == (ArenaNode *)((u8 *)node + oldSize + 0x10) && next->isFree != 0 && next->size >= diff) {
                newNext = next->next;
                next->size = next->size - diff;
                if (newNext != NULL) {
                    newNext->prev = (ArenaNode *)((u8 *)next + diff);
                }
                node->next = (ArenaNode *)((u8 *)next + diff);
                node->size = size;
                func_80096AD0(node->next, next, 0x10, size);
            } else {
                newPtr = func_80087394(arena, size);
                if (newPtr != NULL) {
                    bcopy(newPtr, ptr, node->size);
                    func_80087560(arena, ptr);
                }
                ptr = newPtr;
            }
        } else if (size < oldSize) {
            next = node->next;
            if (next != NULL && next->isFree != 0) {
                overNext = *next;
                newNext = (ArenaNode *)((u8 *)node + ((size + 0xF) & ~0xF) + 0x10);
                *newNext = overNext;
                newNext->size = newNext->size + node->size - size;
                node->next = newNext;
                node->size = size;
                if (newNext->next != NULL) {
                    newNext->next->prev = newNext;
                }
            } else if (size + 0x10 < oldSize) {
                newNext = (ArenaNode *)((u8 *)node + ((size + 0xF) & ~0xF) + 0x10);
                newNext->next = next;
                newNext->prev = node;
                newNext->size = node->size - (((size + 0xF) & ~0xF) + 0x10);
                newNext->isFree = 1;
                newNext->magic = 0x7373;
                node->next = newNext;
                node->size = size;
                if (newNext->next != NULL) {
                    newNext->next->prev = newNext;
                }
            }
        }
    }
    ArenaImpl_Unlock(arena);
    return ptr;
}
