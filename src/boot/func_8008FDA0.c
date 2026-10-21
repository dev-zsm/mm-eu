// FLAGS: -O1 -g0 -mips2
#include "types.h"

typedef struct Thread {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    u16 unk10;
} Thread;

extern Thread *D_80098008;
extern Thread *D_80098010;

s32 func_80091C00(void);
void func_80091C70(s32);
void func_800892E4(void *);
void func_800893E4(s32, void *);
void func_800895D0(s32, void *);

void func_8008FDA0(Thread *arg0, s32 arg1) {
    register s32 temp_s0;
    temp_s0 = func_80091C00();
    if (arg0 == NULL) {
        arg0 = D_80098010;
    }
    if (arg0->unk4 != arg1) {
        arg0->unk4 = arg1;
        if ((arg0 != D_80098010) && (arg0->unk10 != 1)) {
            func_800895D0(arg0->unk8, arg0);
            func_800893E4(arg0->unk8, arg0);
        }
        if (D_80098010->unk4 < D_80098008->unk4) {
            D_80098010->unk10 = 2;
            func_800892E4(&D_80098008);
        }
    }
    func_80091C70(temp_s0);
}
