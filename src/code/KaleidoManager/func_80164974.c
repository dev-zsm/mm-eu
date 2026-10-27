#include "types.h"
typedef struct { s32 pad0[3]; s32 unkC; s32 unk10; s32 pad14[2]; } Ov; /* 0x1C */
extern Ov D_801C9450[2];
extern s32 D_801C9488;
extern s32 D_801C948C;
extern u8 D_801EE480[];
s32 THA_AllocTailAlign16(void *, s32, void *);
void func_80081C2C(void *, void *, s32);
void KaleidoManager_FaultAddrConv(void);
void KaleidoManager_Init(u8 *play) {
    s32 max = 0;
    s32 i;
    s32 sz;
    for (i = 0; i < 2; i++) {
        sz = D_801C9450[i].unk10 - D_801C9450[i].unkC;
        if (max < sz) max = sz;
    }
    D_801C9488 = THA_AllocTailAlign16(play + 0x74, max, play);
    D_801C948C = 0;
    func_80081C2C(D_801EE480, KaleidoManager_FaultAddrConv, 0);
}
