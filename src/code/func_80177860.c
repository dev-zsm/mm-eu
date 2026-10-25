#include "types.h"

typedef struct SchedTask {
    struct SchedTask *next;
    u32 state;
    u32 flags;
    u8 padC[4];
    s32 type;
} SchedTask;

typedef struct {
    u8 pad0[0x300];
    SchedTask *audioListHead;
    SchedTask *gfxListHead;
    SchedTask *audioListTail;
    SchedTask *gfxListTail;
} Sched;

void Sched_QueueTask(Sched *sched, SchedTask *task) {
    s32 type = task->type;

    if (type == 2) {
        if (sched->audioListTail != NULL) {
            sched->audioListTail->next = task;
        } else {
            sched->audioListHead = task;
        }
        sched->audioListTail = task;
    } else {
        if (sched->gfxListTail != NULL) {
            sched->gfxListTail->next = task;
        } else {
            sched->gfxListHead = task;
        }
        sched->gfxListTail = task;
    }
    task->next = NULL;
    task->state = task->flags & 3;
}
