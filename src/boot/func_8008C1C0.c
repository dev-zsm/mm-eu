// FLAGS: -O2 -g0
#include "types.h"

typedef struct Ctx {
    s32 unk0;
    void *unk4;
    void *unk8;
    void *unkC;
    void *unk10;
    void *unk14;
    void *unk18;
} Ctx;

extern Ctx D_80098060;
extern s32 D_80098090;
extern u8 D_8009D5F0[];
extern u8 D_8009E7A0[];
extern u8 D_8009E7B8[];
extern u8 D_8009E7C8[];

extern void func_8008F3E0(void *a, void *b, s32 c);
extern void func_8008C330(void);
extern void func_8008D7E0(s32 a, void *b, u32 c);
extern s32 func_8008FE80(s32 a);
extern void func_8008FDA0(s32 a, s32 b);
extern s32 func_80091C00(void);
extern void func_80091C70(s32 a);
extern void func_80095950(void *a);
extern void func_80089FE0(void *a, s32 b, void *c, void *d, void *e, s32 f);
extern void func_8008C810(void);
extern void func_8008C400(void);
extern void func_80090260(void);

void func_8008C1C0(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 sp2C;
    s32 sp28;
    s32 temp_v0;

    if (D_80098060.unk0 == 0) {
        func_8008F3E0((void *)a1, (void *)a2, a3);
        func_8008F3E0(D_8009E7A0, D_8009E7B8, 1);
        if (D_80098090 == 0) {
            func_8008C330();
        }
        func_8008D7E0(8, D_8009E7A0, 0x22222222);
        sp28 = -1;
        temp_v0 = func_8008FE80(0);
        if (temp_v0 < a0) {
            sp28 = temp_v0;
            func_8008FDA0(0, a0);
        }
        sp2C = func_80091C00();
        D_80098060.unk0 = 1;
        D_80098060.unk8 = (void *)a1;
        D_80098060.unk4 = D_8009D5F0;
        D_80098060.unkC = D_8009E7A0;
        D_80098060.unk10 = D_8009E7C8;
        D_80098060.unk14 = (void *)func_8008C810;
        D_80098060.unk18 = (void *)func_80090260;
        func_80089FE0(D_8009D5F0, 0, (void *)func_8008C400, &D_80098060, D_8009E7A0, a0);
        func_80095950(D_8009D5F0);
        func_80091C70(sp2C);
        if (sp28 != -1) {
            func_8008FDA0(0, sp28);
        }
    }
}
