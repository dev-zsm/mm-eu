// FLAGS: -O2 -g0
#include "types.h"
typedef struct Pool {
    void *head;
    u32 start;
    u8 pad8[0x19];
    u8 unk21;
} Pool;
void bzero(void *a, u32 b);
void ArenaImpl_LockInit(void *p);
void __osMallocAddHeap(void *p, u32 a, s32 b);
void __osMallocInit(Pool *arg0, u32 arg1, s32 arg2) {
    bzero(arg0, 0x24);
    ArenaImpl_LockInit(arg0);
    __osMallocAddHeap(arg0, arg1, arg2);
    arg0->unk21 = 1;
}
