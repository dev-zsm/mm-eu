// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u32 *unk0;
    u32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    u32 *unk14;
} Ring;

typedef struct {
    u8 pad0[0x10];
    s16 unk10;
} Ctl;

extern u32 __osDisableInt(void);
extern void __osRestoreInt(u32 irq);
extern void func_800892E4(void *p);
extern u32 func_8008942C(Ring *p);
extern void osStartThread(u32 a);
extern Ctl *D_80098010;

s32 osSendMesg(Ring *p, u32 v, s32 mode) {
    u32 irq;
    s32 idx;
    u32 r;
    irq = __osDisableInt();
    if (p->unk8 >= p->unk10) {
        do {
            if (mode != 1) {
                __osRestoreInt(irq);
                return -1;
            }
            D_80098010->unk10 = 8;
            func_800892E4(&p->unk4);
        } while (p->unk8 >= p->unk10);
    }
    idx = (p->unkC + p->unk8) % p->unk10;
    p->unk14[idx] = v;
    p->unk8++;
    if (*p->unk0 != 0) {
        r = func_8008942C(p);
        osStartThread(r);
    }
    __osRestoreInt(irq);
    return 0;
}
