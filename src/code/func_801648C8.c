#include "types.h"

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
} KaleidoOvl;

extern void func_80085074(u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4);
extern u32 D_801C9488;
extern KaleidoOvl *D_801C948C;

void KaleidoManager_LoadOvl(KaleidoOvl *ovl) {
    ovl->unk0 = D_801C9488;
    func_80085074(ovl->unk4, ovl->unk8, ovl->unkC, ovl->unk10, ovl->unk0);
    ovl->unk14 = ovl->unk0 - ovl->unkC;
    D_801C948C = ovl;
}
