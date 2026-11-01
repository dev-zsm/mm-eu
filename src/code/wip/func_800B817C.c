#include "types.h"
typedef struct { u8 pad0[4]; u32 unk4; u8 pad8[0x1F - 8]; s8 unk1F; u8 pad20[0x92 - 0x20]; s16 unk92; f32 unk94; u8 pad98[0x138 - 0x98]; void *unk138; } A;
typedef struct { u8 pad0[0xBE]; s16 unkBE; u8 padC0[0x730 - 0xC0]; s32 unk730; } P;
extern f32 D_801AF824[];
extern f32 D_801D4B14;
extern s32 Attention_ActorIsInRange(A *, f32);
s32 Attention_ShouldReleaseLockOn(A *actor, P *player, s32 arg2) {
    s16 d;
    s16 ad;
    f32 f;
    if (actor->unk138 == 0 || !(actor->unk4 & 1) || (actor->unk4 & 0x08000000)) {
        return 1;
    }
    if (arg2 == 0) {
        d = (s16)(actor->unk92 - 0x8000) - player->unkBE;
        if (d < 0) {
            ad = -d;
        } else {
            ad = d;
        }
        if (player->unk730 == 0 && ad >= 0x2AAB) {
            f = D_801D4B14;
        } else {
            f = actor->unk94;
        }
        return Attention_ActorIsInRange(actor, D_801AF824[actor->unk1F * 2] * f) == 0;
    }
    return 0;
}
