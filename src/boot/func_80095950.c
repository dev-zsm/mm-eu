// FLAGS: -O1 -g0 -mips2
#include "types.h"

typedef struct OSThread {
    /* 0x00 */ struct OSThread *next;
    /* 0x04 */ s32 priority;
    /* 0x08 */ struct OSThread **queue;
    /* 0x0C */ struct OSThread *tlnext;
    /* 0x10 */ u16 state;
    /* 0x12 */ u16 flags;
} OSThread;

extern OSThread *D_80098008;
extern OSThread *D_80098010;

s32 __osDisableInt(void);
void __osRestoreInt(s32);
void func_800892E4(OSThread **);
void func_800893E4(OSThread **, OSThread *);
OSThread *func_8008942C(OSThread **);
void func_80089444(void);

void osStartThread(OSThread *t) {
    register s32 saveMask;

    saveMask = __osDisableInt();
    switch (t->state) {
        case 8:
            t->state = 2;
            func_800893E4(&D_80098008, t);
            break;
        case 1:
            if (t->queue == NULL || t->queue == &D_80098008) {
                t->state = 2;
                func_800893E4(&D_80098008, t);
            } else {
                t->state = 8;
                func_800893E4(t->queue, t);
                func_800893E4(&D_80098008, func_8008942C(t->queue));
            }
            break;
    }
    if (D_80098010 == NULL) {
        func_80089444();
    } else {
        if (D_80098010->priority < D_80098008->priority) {
            D_80098010->state = 2;
            func_800892E4(&D_80098008);
        }
    }
    __osRestoreInt(saveMask);
}
