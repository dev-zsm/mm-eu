#include "types.h"

extern s32 D_801C946C[];
extern s32 D_801C948C;
extern void KaleidoManager_ClearOvl(s32 ovl);
extern void KaleidoManager_LoadOvl(s32 *ovl);

void KaleidoScopeCall_LoadPlayer(void) {
    if ((u32)D_801C948C != (u32)D_801C946C) {
        if (D_801C948C != 0) {
            KaleidoManager_ClearOvl(D_801C948C);
        }
        KaleidoManager_LoadOvl(D_801C946C);
    }
}
