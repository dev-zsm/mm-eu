#include "types.h"

typedef struct { u8 pad0[0x24]; u32 unk24; u32 unk28; u32 unk2C; u32 unk30; u32 unk34; } ActorSrc;
typedef struct { u32 unk0; u32 unk4; u32 unk8; u32 unkC; u32 unk10; } ActorDst;

ActorDst *Actor_GetWorld(ActorDst *a0, ActorSrc *a1) {
    *a0 = *(ActorDst *)&a1->unk24;
    return a0;
}
