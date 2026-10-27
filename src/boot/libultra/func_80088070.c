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

s32 osRecvMesg(OSMesgQueue *mq, s32 *msg, s32 flags) {
    register s32 prevInt;
    register OSThread *thread;

    prevInt = __osDisableInt();
    while (mq->validCount == 0) {
        if (flags == 0) {
            __osRestoreInt(prevInt);
            return -1;
        }
        D_80098010->state = 8;
        func_800892E4(&mq->mtqueue);
    }
    if (msg != NULL) {
        *msg = mq->msg[mq->first];
    }
    mq->first = (mq->first + 1) % mq->msgCount;
    mq->validCount--;
    if (mq->fullqueue->next != NULL) {
        thread = func_8008942C(&mq->fullqueue);
        osStartThread(thread);
    }
    __osRestoreInt(prevInt);
    return 0;
}
