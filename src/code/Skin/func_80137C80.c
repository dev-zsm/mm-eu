#include "types.h"

typedef struct {
    u8 pad0[0x20];
    void *unk20;
    void *unk24;
} Ptrs;

extern void ZeldaArena_Free(void *ptr);

void func_80137C80(Ptrs *p, s32 arg1) {
    if (p->unk20 != NULL) {
        ZeldaArena_Free(p->unk20);
    }
    if (p->unk24 != NULL) {
        ZeldaArena_Free(p->unk24);
    }
}
