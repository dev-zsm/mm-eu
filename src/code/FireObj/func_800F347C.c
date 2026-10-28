// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0xC];
    f32 unkC;
    u8 pad10[0x1C];
    u8 unk2C[0x40];
    volatile s16 unk6C; // volatile only to stop the compiler reusing unkC across the stores (match-only)
    volatile s16 unk6E;
    volatile s16 unk70;
    u8 pad72[6];
    u8 unk78[1];
} Fire;

extern u8 D_801BE400[];
extern void FireObj_InitWithParams(s32, Fire *, u8 *);
extern void Collider_InitCylinder(s32, void *);
extern void Collider_SetCylinder(s32, void *, s32, void *);
extern void FireObj_InitLight(s32, void *, u8 *, Fire *);

void FireObj_Init(s32 a0, Fire *f, u8 *params, s32 a3) {
    s32 pad;

    FireObj_InitWithParams(a0, f, params);
    Collider_InitCylinder(a0, f->unk2C);
    Collider_SetCylinder(a0, f->unk2C, a3, D_801BE400);
    f->unk6C = (s32)(f->unkC * 4000.0f + 2.5f);
    f->unk6E = (s32)(f->unkC * 16000.0f);
    f->unk70 = (s32)(f->unkC * -1728.0f);
    FireObj_InitLight(a0, f->unk78, params + 0xC, f);
}
