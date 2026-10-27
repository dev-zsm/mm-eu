#include "types.h"

typedef struct {
    /* 0x00 */ u8 pad0[8];
    /* 0x08 */ s32 unk8;
} Node;

typedef struct {
    /* 0x000 */ u8 pad0[0x818];
    /* 0x818 */ Node *unk818;
} Play;

typedef struct {
    /* 0x000 */ u8 pad0[0x1C0];
    /* 0x1C0 */ Node *unk1C0;
    /* 0x1C4 */ s32 unk1C4;
} Eff;

extern Play *Effect_GetPlayState(void);
extern void LightContext_RemoveLight(Play *, Node **, Node *);

void EffectShieldParticle_Destroy(Eff *a0) {
    s32 pad[2];
    Play *p;

    if (a0 != 0) {
        if (a0->unk1C4 == 1) {
            if (a0->unk1C0 == Effect_GetPlayState()->unk818) {
                Effect_GetPlayState()->unk818 = a0->unk1C0->unk8;
            }
            p = Effect_GetPlayState();
            LightContext_RemoveLight(p, &Effect_GetPlayState()->unk818, a0->unk1C0);
        }
    }
}
