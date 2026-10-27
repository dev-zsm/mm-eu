#include "types.h"

typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 pad1[0x23];
    /* 0x24 */ s32 unk24;
} Struct_80136C6C;

extern void AnimTaskQueue_AddLoadPlayerFrame(s32, s32, s32, s32, s32);
extern void AnimTaskQueue_AddInterp(s32, s32, s32, s32, f32);

void PlayerAnimation_BlendToMorph(s32 arg0, Struct_80136C6C *arg1, s32 arg2, f32 arg3, s32 arg4, f32 arg5, f32 arg6, s32 arg7) {
    s32 sp28;

    AnimTaskQueue_AddLoadPlayerFrame(arg0, arg2, (s32)arg3, arg1->unk0, arg1->unk24);
    sp28 = (arg7 + 0xF) & ~0xF;
    AnimTaskQueue_AddLoadPlayerFrame(arg0, arg4, (s32)arg5, arg1->unk0, sp28);
    AnimTaskQueue_AddInterp(arg0, arg1->unk0, arg1->unk24, sp28, arg6);
}
