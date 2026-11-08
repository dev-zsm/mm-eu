#include "types.h"

typedef struct {
    u8 pad0[0x8];
    s32 unk8;
    u8 pad0C[0x12];
    s8 unk1E;
} Fn800BB21CB;

typedef struct {
    u8 pad0[0xEC];
    u8 unkEC[0x54];
    Fn800BB21CB *unk140;
} Fn800BB21CAct;

typedef struct {
    u8 pad0[0x158];
    Fn800BB21CAct *unk158;
    u8 pad15C[0x50];
    Fn800BB21CAct *unk1AC;
    Fn800BB21CAct *unk1B0;
} Fn800BB21CCtx;

typedef struct {
    u8 pad0[0x730];
    Fn800BB21CAct *unk730;
} Fn800BB21CPlayer;

typedef struct {
    u8 pad0[0x1CCC];
    Fn800BB21CPlayer *unk1CCC;
} Fn800BB21CPlay;

extern void Actor_Destroy(Fn800BB21CAct *, Fn800BB21CPlay *);
extern s32 Actor_RemoveFromCategory(Fn800BB21CPlay *, Fn800BB21CCtx *, Fn800BB21CAct *);
extern void Actor_FreeOverlay(Fn800BB21CB *);
extern void Camera_ChangeMode(s32, s32);
extern void ZeldaArena_Free(Fn800BB21CAct *);
extern void Player_ReleaseLockOn(Fn800BB21CPlayer *);
extern s16 Play_GetActiveCamId(Fn800BB21CPlay *);
extern s32 Play_GetCamera(Fn800BB21CPlay *, s16);
extern void AudioSfx_StopByPos(void *);

s32 Actor_Delete(Fn800BB21CCtx *arg0, Fn800BB21CAct *arg1, Fn800BB21CPlay *arg2) {
    s32 pad; // matching: unused, pads the frame to the ROM size
    Fn800BB21CPlayer *player;
    s32 ret;
    Fn800BB21CB *sp20;

    player = arg2->unk1CCC;
    sp20 = arg1->unk140;
    if (player != NULL && arg1 == player->unk730) {
        Player_ReleaseLockOn(player);
        Camera_ChangeMode(Play_GetCamera(arg2, Play_GetActiveCamId(arg2)), 0);
    }
    if (arg1 == arg0->unk158) {
        arg0->unk158 = NULL;
    }
    if (arg1 == arg0->unk1AC) {
        arg0->unk1AC = NULL;
    }
    if (arg1 == arg0->unk1B0) {
        arg0->unk1B0 = NULL;
    }
    AudioSfx_StopByPos(arg1->unkEC);
    Actor_Destroy(arg1, arg2);
    ret = Actor_RemoveFromCategory(arg2, arg0, arg1);
    ZeldaArena_Free(arg1);
    if (sp20->unk8 != 0) {
        sp20->unk1E--;
        Actor_FreeOverlay(sp20);
    }
    return ret;
}
