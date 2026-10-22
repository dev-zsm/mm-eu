// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x1C];
    s16 unk1C;
    u8 pad1[0x92 - 0x1E];
    s16 unk92;
    u8 pad2[0xBE - 0x94];
    s16 unkBE;
    u8 pad3[0x144 - 0xC0];
    void *unk144;
} Actor60;

s32 Actor_TalkOfferAccepted(Actor60 *, s32);
void Actor_OfferTalkNearColChkInfoCylinder(Actor60 *, s32);
void EnAObj_Talk(void);

void EnAObj_Idle(Actor60 *arg0, s32 arg1) {
    s16 temp;
    s32 absDiff;

    if (Actor_TalkOfferAccepted(arg0, arg1) != 0) {
        arg0->unk144 = EnAObj_Talk;
    } else {
        temp = arg0->unk92 - arg0->unkBE;
        if (temp < 0) {
            absDiff = -temp;
        } else {
            absDiff = temp;
        }
        if ((absDiff < 0x2800) || ((arg0->unk1C == 1) && (absDiff >= 0x5801))) {
            Actor_OfferTalkNearColChkInfoCylinder(arg0, arg1);
        }
    }
}
