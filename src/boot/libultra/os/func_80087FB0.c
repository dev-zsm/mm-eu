// FLAGS: -O1 -g0 -mips2
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
    register u32 irq;
    register u16 mode;

    irq = __osDisableInt();
    if (p == NULL) {
        mode = 4;
    } else {
        mode = p->unk10;
    }
    switch (mode) {
        case 4:
            D_80098010->unk10 = 1;
            func_800892E4(0);
            break;
        case 2:
        case 8:
            p->unk10 = 1;
            func_800895D0(p->unk8, p);
            break;
        default:
            break;
    }
    __osRestoreInt(irq);
}
