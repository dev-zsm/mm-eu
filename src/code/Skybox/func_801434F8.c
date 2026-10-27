#include "types.h"

typedef struct { s32 a, b, c, d, e; } Ent;
typedef struct { u8 pad0[0x184]; s32 unk184; } Sky;
extern Ent D_801C7404[];
extern s32 Skybox_CalculateFace128(Sky *s, s32 a1, s32 a2, s32 a3, s32 b, s32 c, s32 d, s32 e, s32 i);

void Skybox_Calculate128(Sky *s, s32 n) {
    s32 i;
    s32 r = 0;


    for (i = 0; i < n; i++) {
        r = Skybox_CalculateFace128(s, s->unk184, r, D_801C7404[i].a, D_801C7404[i].b, D_801C7404[i].c, D_801C7404[i].d, D_801C7404[i].e, i);
    }
}
