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

extern u32 __osDisableInt(void);
extern void __osRestoreInt(u32 irq);
extern void func_800892E4(s32 a);
extern void func_800895D0(s32 a, Obj *p);
extern Ctl *D_80098010;

void osStopThread(Obj *p) {
    u32 irq;
    u16 mode;
    s32 k;
    irq = __osDisableInt();
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
    __osRestoreInt(irq);
}
