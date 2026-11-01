#include "types.h"

typedef struct {
    u8 pad0[0x10];
    void *unk10;
    void *unk14;
} PreRender;

void func_801713C0(PreRender *prerender);

void PreRender_SaveFramebuffer(PreRender *prerender) {
    if (prerender->unk14 != NULL && prerender->unk10 != NULL) {
        func_801713C0(prerender);
    }
}
