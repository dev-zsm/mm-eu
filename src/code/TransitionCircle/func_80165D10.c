#include "types.h"

typedef struct { u8 pad0[8]; s32 unk8; u8 pad0C[4]; s32 unk10; u8 pad14[2]; u8 unk16; } TransCircle;

u8 Math_StepToF(void *a0, s32 a1, s32 a2);

void TransitionCircle_Update(TransCircle *a0) {
    a0->unk16 = Math_StepToF((u8 *)a0 + 4, a0->unk10, a0->unk8);
}
