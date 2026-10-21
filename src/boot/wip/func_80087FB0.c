// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x8];
    s32 unk8;
    u8 pad_c[4];
    u16 unk10;
} Obj;

typedef struct {
    u8 pad0[0x10];
    s16 unk10;
} Ctl;

extern u32 func_80091C00(void);
extern void func_80091C70(u32 irq);
extern void func_800892E4(s32 a);
extern void func_800895D0(s32 a, Obj *p);
extern Ctl *D_80098010;

void func_80087FB0(Obj *p) {
    u32 irq;
    u16 mode;
    s32 k;
    irq = func_80091C00();
    mode = 4;
    if (p != NULL) {
        mode = p->unk10;
    }
    k = mode;
    if (k == 2) {
        p->unk10 = 1;
        func_800895D0(p->unk8, p);
    } else if (k == 4) {
        D_80098010->unk10 = 1;
        func_800892E4(0);
    } else if (k == 8) {
        p->unk10 = 1;
        func_800895D0(p->unk8, p);
    }
    func_80091C70(irq);
}
