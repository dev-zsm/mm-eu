#include "types.h"
extern void Math_StepToF(void *a0, f32 a1, f32 a2, void *a3);
void Cutscene_StepTimer(s32 a0, u8 *a1, f32 a2) {
    Math_StepToF(a1 + 0xC, a2, 0.1f, a1);
}
