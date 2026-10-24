#include "types.h"

extern void PreRender_RestoreBuffer(u8 *, s32, void *, void *);

void PreRender_SaveZBuffer(u8 *arg0, s32 arg1) {
    void *a3 = *(void **)(arg0 + 0x20);
    void *a2;

    if (a3 != 0) {
        a2 = *(void **)(arg0 + 0x1C);
        if (a2 != 0) {
            PreRender_RestoreBuffer(arg0, arg1, a2, a3);
        }
    }
}
