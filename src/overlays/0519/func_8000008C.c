// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct E {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ u8 unk8;
    /* 0x9 */ u8 pad9[3];
    /* 0xC */ f32 unkC;
} E;

extern E D_80B72EC8[];
s32 func_80134AE8();
void func_80137788(s32, s32, f32, f32, f32, s32, f32);

void func_8000008C(s32 arg0, s32 arg1) {
    func_80137788(arg0 + 0x144, D_80B72EC8[arg1].unk0, 1.0f, 0.0f, func_80134AE8(D_80B72EC8[arg1].unk0), D_80B72EC8[arg1].unk8, D_80B72EC8[arg1].unkC);
}
