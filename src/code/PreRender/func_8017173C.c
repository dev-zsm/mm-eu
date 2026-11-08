#include "types.h"
#include "generated/code_funcs.h"


void PreRender_SaveZBuffer(struct PreRender *this, union Gfx **gfxP) {
    void *a3 = *(void **)((u8 *)this + 0x20);
    void *a2;

    if (a3 != 0) {
        a2 = *(void **)((u8 *)this + 0x1C);
        if (a2 != 0) {
            PreRender_RestoreBuffer(this, gfxP, a2, a3);
        }
    }
}
