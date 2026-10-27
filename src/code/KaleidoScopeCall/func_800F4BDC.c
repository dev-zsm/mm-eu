// FLAGS: -O2 -g3 -mips2
#include "types.h"
typedef struct {
    /* 0x000 */ u8 pad0[0x1F4];
    /* 0x1F4 */ f32 unk1F4;
    /* 0x1F8 */ u8 pad1F8[0xC];
    /* 0x204 */ s16 unk204;
    /* 0x206 */ u8 pad206[6];
    /* 0x20C */ f32 unk20C;
    /* 0x210 */ f32 unk210;
    /* 0x214 */ f32 unk214;
    /* 0x218 */ f32 unk218;
    /* 0x21C */ f32 unk21C;
    /* 0x220 */ f32 unk220;
    /* 0x224 */ u8 pad224[0x16];
    /* 0x23A */ s16 unk23A;
    /* 0x23C */ u8 pad23C[0x1C];
    /* 0x258 */ s16 unk258;
    /* 0x25A */ s16 unk25A;
    /* 0x25C */ u8 pad25C[2];
    /* 0x25E */ s16 unk25E;
    /* 0x260 */ s16 unk260;
    /* 0x262 */ s16 unk262;
    /* 0x264 */ s16 unk264;
    /* 0x266 */ u8 pad266[2];
    /* 0x268 */ s16 unk268;
    /* 0x26A */ s16 unk26A;
    /* 0x26C */ u8 pad26C[0x18];
    /* 0x284 */ s16 unk284;
    /* 0x286 */ u8 pad286[0x18];
    /* 0x29E */ s16 unk29E;
    /* 0x2A0 */ s16 unk2A0;
    /* 0x2A2 */ u8 pad2A2[0x18];
    /* 0x2BA */ s16 unk2BA;
    /* 0x2BC */ s16 unk2BC;
} Sub;
typedef struct { u8 pad[0xB50]; s16 unkB50; } Other;
void func_800897D0(Sub *, s32);
void View_Init(Sub *, s32);
extern u8 D_801EAE2E;
extern Other *D_801EB7E0;

void func_800F4BDC(u8 *arg0) {
    Sub *sp18;
    s32 pad;
    Sub *p;

    p = (Sub *)(arg0 + 0x16D30);
    sp18 = p;
    func_800897D0(p, 0x2D0);
    p->unk21C = 160.0f;
    p->unk218 = 160.0f;
    p->unk214 = 160.0f;
    p->unk210 = 160.0f;
    p->unk1F4 = -64.0f;
    p->unk20C = 936.0f;
    p->unk220 = -314.0f;
    p->unk204 = D_801EAE2E;
    p->unk23A = D_801EB7E0->unkB50 + 3;
    p->unk258 = 0xB;
    p->unk25A = 0;
    p->unk25E = 0x3E7;
    p->unk260 = D_801EB7E0->unkB50 + 3;
    p->unk262 = 0x3E7;
    p->unk264 = 0x3E7;
    p->unk268 = 0;
    p->unk26A = D_801EB7E0->unkB50 + 3;
    p->unk284 = 2;
    p->unk2A0 = -1;
    p->unk2BA = 0x140;
    p->unk2BC = 0x28;
    p->unk29E = 0x64;
    View_Init(p, *(s32 *)arg0);
}
