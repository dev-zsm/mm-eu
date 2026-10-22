// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x730];
    s32 unk730;
    u8 pad1[0xA6C - 0x734];
    s32 unkA6C;
    u8 pad2[0xA78 - 0xA70];
    s32 unkA78;
} Sub;

typedef struct {
    u8 pad0[0x1CCC];
    Sub *unk1CCC;
} Top;

void Player_ClearZTargeting(Sub *);
void *Play_GetCamera(Top *, s32);
void Camera_SetViewParam(void *, s32, s32);
void Camera_ChangeMode(void *, s32);

void Player_SetAutoLockOnActor(Top *arg0, s32 arg1) {
    Sub *sp1C;

    sp1C = arg0->unk1CCC;
    Player_ClearZTargeting(sp1C);
    sp1C->unk730 = arg1;
    sp1C->unkA78 = arg1;
    sp1C->unkA6C |= 0x10000;
    Camera_SetViewParam(Play_GetCamera(arg0, 0), 8, arg1);
    Camera_ChangeMode(Play_GetCamera(arg0, 0), 9);
}
