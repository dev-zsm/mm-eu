#include "types.h"
#include "actor.h"

void func_80000000(Actor *thisx, PlayState *play) {
    *(f32 *)((u8 *)thisx + 0x28) += 4.0f;
}
