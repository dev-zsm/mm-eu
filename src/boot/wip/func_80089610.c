// FLAGS: -O1 -g3 -mips2
#include "types.h"

typedef struct Obj {
    struct Obj *unk0;
    s32 unk4;
    struct Obj *unk8;
    struct Obj *unkC;
    u16 unk10;
} Obj;

extern Obj *D_80098010;
extern Obj *D_8009800C;

void *func_80091C00(void);
void func_80091C70(void *a);
void func_80089444(void);
void func_800895D0(Obj *a0, Obj *a1);

void func_80089610(Obj *arg) {
    void *s0;
    Obj *s1;
    Obj *s2;

    s0 = func_80091C00();
    if (arg == NULL) {
        arg = D_80098010;
    } else if (arg->unk10 != 1) {
        func_800895D0(arg->unk8, arg);
    }

    if (D_8009800C == arg) {
        D_8009800C = arg->unkC;
    } else {
        s1 = D_8009800C;
        if (s1->unk4 != -1) {
            do {
                s2 = s1->unkC;
                if (s2 == arg) {
                    s1->unkC = arg->unkC;
                    break;
                }
                s1 = s2;
            } while (s1->unk4 != -1);
        }
    }

    if (arg == D_80098010) {
        func_80089444();
    }
    func_80091C70(s0);
}
