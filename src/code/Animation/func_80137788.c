#include "types.h"

extern void Animation_ChangeImpl(s32 a0, s32 a1, f32 a2, f32 a3, f32 a4, u8 a5, f32 a6, s32 a7);

void Animation_Change(s32 a0, s32 a1, f32 a2, f32 a3, f32 a4, u8 a5, f32 a6) {
    Animation_ChangeImpl(a0, a1, a2, a3, a4, a5, a6, 0);
}
