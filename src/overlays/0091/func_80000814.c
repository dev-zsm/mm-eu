#include "types.h"
typedef struct { char pad[0x16]; s16 unk16; char pad18[0x218]; void *unk230; char pad234[8]; s16 unk23C; char pad23E[2]; f32 unk240; } S;
extern s32 D_808AFBE8;
void func_80000814(S *arg0) {
    arg0->unk230 = &D_808AFBE8;
    arg0->unk240 = 0.0f;
    arg0->unk23C = arg0->unk16;
    arg0->unk230 = &D_808AFBE8;
}
