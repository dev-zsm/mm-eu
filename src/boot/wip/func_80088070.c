// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 *unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 *unk14;
} Func80088070Struct;

extern u8 *D_80098010;

s32 func_80091C00(void);
void func_80091C70(s32);
void func_800892E4(Func80088070Struct *);
s32 func_8008942C(s32 *);
void func_80095950(s32);

s32 func_80088070(Func80088070Struct *arg0, s32 *arg1, s32 arg2) {
    s32 temp_s0;
    s32 temp_s1;

    temp_s0 = func_80091C00();
    while (arg0->unk8 == 0) {
        if (arg2 == 0) {
            func_80091C70(temp_s0);
            return -1;
        }
        *(s16 *)(D_80098010 + 0x10) = 8;
        func_800892E4(arg0);
    }
    if (arg1 != NULL) {
        *arg1 = arg0->unk14[arg0->unkC];
    }
    arg0->unkC = (s32) (arg0->unkC + 1) % arg0->unk10;
    arg0->unk8 -= 1;
    if (*arg0->unk4 != 0) {
        temp_s1 = func_8008942C((s32 *) &arg0->unk4);
        func_80095950(temp_s1);
    }
    func_80091C70(temp_s0);
    return 0;
}
