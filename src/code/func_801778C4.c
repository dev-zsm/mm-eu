#include "types.h"

typedef struct {
    u8 pad0[4];
    u32 flags;
    u8 pad8[8];
    s32 state;
} SchedTask;

typedef struct {
    u8 pad0[0x310];
    SchedTask *task;
} Sched;

extern u8 D_801D7870[];

void func_8008198C(u8 *arg0);
void func_8008B0F0(void);

void Sched_Yield(Sched *sched) {
    SchedTask *task = sched->task;

    if (task->state == 2) {
        func_8008198C(D_801D7870);
    } else if (!(task->flags & 0x10)) {
        task->flags |= 0x10;
        func_8008B0F0();
    }
}
