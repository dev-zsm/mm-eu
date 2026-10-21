// FLAGS: -O1 -g0 -mips2
#include "types.h"

typedef struct Queue {
    s32 *unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 *unk14;
} Queue;

typedef struct Thread {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    u16 unk10;
} Thread;

extern Thread *D_80098010;

s32 func_80091C00(void);
void func_80091C70(s32);
void func_800892E4(void *);
s32 func_8008942C(void *);
void func_80095950(s32);

s32 func_8008FC50(Queue *arg0, s32 arg1, s32 arg2) {
    register s32 temp_s0;
    register s32 temp_s1;

    temp_s0 = func_80091C00();
    while (arg0->unk8 >= arg0->unk10) {
        if (arg2 == 1) {
            D_80098010->unk10 = 8;
            func_800892E4(&arg0->unk4);
        } else {
            func_80091C70(temp_s0);
            return -1;
        }
    }
    arg0->unkC = (arg0->unkC + arg0->unk10 - 1) % arg0->unk10;
    arg0->unk14[arg0->unkC] = arg1;
    arg0->unk8 = arg0->unk8 + 1;
    if (*arg0->unk0 != 0) {
        temp_s1 = func_8008942C(arg0);
        func_80095950(temp_s1);
    }
    func_80091C70(temp_s0);
    return 0;
}
