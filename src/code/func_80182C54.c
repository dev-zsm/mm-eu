// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct { u8 pad0[0x10]; f32 unk10; f32 unk14; f32 unk18; u8 pad1[0x30 - 0x1C]; f32 unk30; f32 unk34; f32 unk38; } Mtx;
typedef struct { f32 unk0; f32 unk4; f32 unk8; } Vec3f;

extern void *D_801F3644;

void Matrix_MultVecY(f32 arg0, Vec3f *arg1) {
    Mtx *m = D_801F3644;

    arg1->unk0 = m->unk30 + m->unk10 * arg0;
    arg1->unk4 = m->unk34 + m->unk14 * arg0;
    arg1->unk8 = m->unk38 + m->unk18 * arg0;
}
