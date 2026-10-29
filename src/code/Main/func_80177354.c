#include "types.h"

typedef struct {
    /* 0x00 */ u8 pad0[0x9C];
    /* 0x9C */ s32 unk9C;
    /* 0xA0 */ u8 padA0[0x228];
    /* 0x2C8 */ u8 unk2C8;
} PadMgr;

extern PadMgr *D_801C9E40;
extern void func_800897D0(void *, s32);
extern void func_8008F3E0(void *, void *, s32, void *);
extern void func_80086690();
extern void func_80092E20(u8);
extern void func_80089FE0();
extern void func_80095950(void *);
extern void func_801771D0();
extern void PadMgr_UnlockPadData(void);
extern void PadMgr_ReleaseSerialEventQueue(s32);

void func_80177354(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    func_800897D0(D_801C9E40, 0x480);
    D_801C9E40->unk9C = a1;
    func_8008F3E0((u8 *)D_801C9E40 + 0x4C, (u8 *)D_801C9E40 + 0x24, 1, D_801C9E40);
    func_8008F3E0((u8 *)D_801C9E40 + 0x64, (u8 *)D_801C9E40 + 0x28, 1, D_801C9E40);
    PadMgr_UnlockPadData();
    func_80086690(a0, D_801C9E40, (u8 *)D_801C9E40 + 0x14);
    D_801C9E40->unk2C8 = 4;
    func_80092E20(D_801C9E40->unk2C8);
    PadMgr_ReleaseSerialEventQueue(a0);
    func_80089FE0((u8 *)D_801C9E40 + 0xA0, a2, func_801771D0, D_801C9E40, a4, a3);
    func_80095950((u8 *)D_801C9E40 + 0xA0);
}
