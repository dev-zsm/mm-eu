#include "types.h"
typedef struct PlayerAnimMorph { u8 unk0; u8 pad1[0x1F]; s32 unk20; s32 unk24; } PlayerAnimMorph;
void AnimTaskQueue_AddCopy(s32, s32, s32, s32);
void PlayerAnimation_CopyMorphToJoint(s32 a0, PlayerAnimMorph *a1) {
    AnimTaskQueue_AddCopy(a0, a1->unk0, a1->unk20, a1->unk24);
}
