#include "types.h"

typedef struct {
    u32 pad : 4;
    u32 t : 2;
    u32 b1 : 1;
    u32 b0 : 1;
    u32 addr : 24;
    u32 unk4;
} Ent;

typedef struct {
    s16 pad0;
    s16 unk2;
} Info;

extern Info *D_801FAD08;
extern s32 AudioHeap_AllocSampleCache();
extern void func_80191548();
extern void func_80191424();

s32 AudioLoad_SyncLoadSample(Ent *a0, s32 a1) {
    s32 r;

    if (a0->b0 == 1) {
        if (a0->t != 0) {
            r = AudioHeap_AllocSampleCache(a0->addr, a1, a0->unk4, a0->t, 1);
            if (r == 0) {
                return -1;
            }
            if (a0->t == 1) {
                func_80191548(a0->unk4, r, a0->addr, D_801FAD08->unk2);
            } else {
                func_80191424(a0->unk4, r, a0->addr, a0->t);
            }
            a0->t = 0;
            a0->unk4 = r;
        }
    }
}
