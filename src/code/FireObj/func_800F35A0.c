#include "types.h"
#include "generated/code_funcs.h"

extern void FireObj_SetState(s32, f32, u8);

void FireObj_SetState2(struct FireObj *fire, f32 dynamicSizeStep, u8 newState) {
    FireObj_SetState(fire, dynamicSizeStep, newState);
}
