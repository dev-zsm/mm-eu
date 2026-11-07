#include "types.h"
#include "actor.h"

void ObjKinoko_Init(Actor *thisx, PlayState *play) {
    *(f32 *)((u8 *)thisx + 0x28) += 4.0f;
}
