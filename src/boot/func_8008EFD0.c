// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u16 unk0;
    u8 unk2;
    u8 pad3[0x11];
    void *unk14;
} Obj;

extern s32 D_80098060;

s32 osPiGetCmdQueue(void *a0, Obj *a1, s32 a2);
s32 osJamMesg(s32 a0, Obj *a1, s32 a2);
s32 osSendMesg(s32 a0, Obj *a1, s32 a2);

s32 osEPiStartDma(void *a0, Obj *a1, s32 a2) {
    s32 r;

    if (D_80098060 == 0) {
        return -1;
    }
    a1->unk14 = a0;
    if (a2 == 0) {
        a1->unk0 = 0xF;
    } else {
        a1->unk0 = 0x10;
    }
    if (a1->unk2 == 1) {
        r = osJamMesg(osPiGetCmdQueue(a0, a1, a2), a1, 0);
    } else {
        r = osSendMesg(osPiGetCmdQueue(a0, a1, a2), a1, 0);
    }
    return r;
}
