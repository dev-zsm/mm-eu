#include "types.h"

typedef struct {
    void *loadedRamAddr;
    u8 pad4[8];
    u8 *vramStart;
    u8 *vramEnd;
    s32 unk14;
} OverlayEntry;

extern s32 D_801C948C;

extern void func_800897D0(void *ptr, s32 size);

void KaleidoManager_ClearOvl(OverlayEntry *ovl) {
    if (ovl->loadedRamAddr != NULL) {
        ovl->unk14 = 0;
        func_800897D0(ovl->loadedRamAddr, ovl->vramEnd - ovl->vramStart);
        ovl->loadedRamAddr = NULL;
        D_801C948C = 0;
    }
}
