// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 func_80100304(void *);

typedef struct {
    u8 pad0[0x18846];
    u16 unk18846;
    u8 pad18848[0xC];
    s32 unk18854;
    u8 pad18858[0x4254];
    u16 unk1CAC;
} SceneCtx;

void Scene_CommandActorList(SceneCtx *arg0, u8 *arg1) {
    arg0->unk18846 = arg1[1];
    arg0->unk18854 = func_80100304(*(void **)(arg1 + 4));
    *(u16 *)((u8 *)arg0 + 0x1CAC) = 0;
}
