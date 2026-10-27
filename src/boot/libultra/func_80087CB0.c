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

typedef struct {
    /* 0x00 */ OSThread *mtqueue;
    /* 0x04 */ OSThread *fullqueue;
    /* 0x08 */ s32 validCount;
    /* 0x0C */ s32 first;
    /* 0x10 */ s32 msgCount;
    /* 0x14 */ s32 *msg;
} OSMesgQueue;

extern OSThread *D_80098010;

s32 __osDisableInt(void);
void __osRestoreInt(s32);
void func_800892E4(OSThread **);
OSThread *func_8008942C(OSThread **);
void osStartThread(OSThread *);

s32 osSendMesg(OSMesgQueue *mq, s32 msg, s32 flags) {
    register s32 prevInt; /* register: -O1 only allocates saved registers for register locals */
    register s32 last;
    register OSThread *thread;

    prevInt = __osDisableInt();
    while (mq->validCount >= mq->msgCount) {
        if (flags == 1) {
            D_80098010->state = 8;
            func_800892E4(&mq->fullqueue);
        } else {
            __osRestoreInt(prevInt);
            return -1;
        }
    }
    last = (mq->first + mq->validCount) % mq->msgCount;
    mq->msg[last] = msg;
    mq->validCount++;
    if (mq->mtqueue->next != NULL) {
        thread = func_8008942C(&mq->mtqueue);
        osStartThread(thread);
    }
    __osRestoreInt(prevInt);
    return 0;
}
