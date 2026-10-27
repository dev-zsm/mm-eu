#include "types.h"

typedef struct {
    u8 pad0[2];
    u8 type;
} AttnArg;

typedef struct {
    u8 pad0[0x38];
    s32 unk38;
    s32 unk3C;
    f32 unk40;
    u8 pad44[0x4B - 0x44];
    u8 unk4B;
    u8 unk4C;
    u8 pad4D[0x8C - 0x4D];
    s32 unk8C;
    s32 unk90;
} Attention;

extern void Attention_SetTatlState(Attention *att, AttnArg *arg, u8 type, s32 a);
extern void Attention_InitReticle(Attention *att, u8 type, s32 a);

void Attention_Init(Attention *att, AttnArg *arg, s32 a) {
    att->unk90 = 0;
    att->unk8C = 0;
    att->unk3C = 0;
    att->unk38 = 0;
    att->unk4B = 0;
    att->unk4C = 0;
    att->unk40 = 0.0f;
    Attention_SetTatlState(att, arg, arg->type, a);
    Attention_InitReticle(att, arg->type, a);
}
