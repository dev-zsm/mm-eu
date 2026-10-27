#include "types.h"

typedef struct {
    /* 0x000 */ u8 pad0[0x208];
    /* 0x208 */ f32 unk208;
    /* 0x20C */ f32 unk20C;
    /* 0x210 */ f32 unk210;
} Struct_80143950;

extern s32 D_801EE360;
extern void Matrix_Translate(f32, f32, f32, s32);
extern void Matrix_Scale(f32, f32, f32, s32);
extern void Matrix_RotateXFApply(f32);
extern void Matrix_RotateYF(f32, s32);
extern void Matrix_RotateZF(f32, s32);
extern void Matrix_ToMtx(s32);

void Skybox_UpdateMatrix(Struct_80143950 *arg0, f32 arg1, f32 arg2, f32 arg3) {
    Matrix_Translate(arg1, arg2, arg3, 0);
    Matrix_Scale(1.0f, 1.0f, 1.0f, 1);
    Matrix_RotateXFApply(arg0->unk208);
    Matrix_RotateYF(arg0->unk20C, 1);
    Matrix_RotateZF(arg0->unk210, 1);
    Matrix_ToMtx(D_801EE360);
}
