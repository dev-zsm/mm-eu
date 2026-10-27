// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0xC];
    u32 vramStart;
    u32 vramEnd;
    s32 vramOffset;
    u8 pad18[4];
} Ovl;

extern Ovl D_801C9450[2];
extern Ovl D_801C9488;
extern Ovl *D_801C948C;
void KaleidoManager_LoadOvl(Ovl *ovl, u32 addr);

u32 KaleidoManager_GetRamAddr(u32 vram) {
    s32 pad[2]; // unused, matches the frame size
    Ovl *ovl;

    if (D_801C948C == 0) {
        ovl = D_801C9450;
        do {
            if (vram >= ovl->vramStart && vram <= ovl->vramEnd) {
                KaleidoManager_LoadOvl(ovl, vram);
                return (s32)vram + ovl->vramOffset;
            }
            ovl++;
        } while (ovl != &D_801C9488);
        return 0;
    }
    if (vram < D_801C948C->vramStart || vram >= D_801C948C->vramEnd) {
        return 0;
    }
    return (s32)vram + D_801C948C->vramOffset;
}
