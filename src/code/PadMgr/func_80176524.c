#include "types.h"
extern s32 PadMgr_AcquireSerialEventQueue(void);
extern s32 func_80089AE4(s32, void *, s32);
extern void func_80089870(void *, s32);
extern void PadMgr_ReleaseSerialEventQueue(s32);
typedef struct { u8 pad[0x2C9]; u8 unk2C9[4]; u8 pad2CD[0xF]; u8 unk2DC[4][0x68]; } PM;
extern PM *D_801C9E40;
void PadMgr_RumbleStop(void) {
    s32 i;
    s32 s = PadMgr_AcquireSerialEventQueue();
    for (i = 0; i < 4; i++) {
        if (D_801C9E40->unk2C9[i] == 1) {
            if (func_80089AE4(s, D_801C9E40->unk2DC[i], i) == 0) {
                func_80089870(D_801C9E40->unk2DC[i], 0);
            }
        }
    }
    PadMgr_ReleaseSerialEventQueue(s);
}
