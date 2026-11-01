#include "types.h"

extern s32 func_80088070();
extern void Sched_QueueTask();
extern void Sched_Yield();
extern s32 Sched_Schedule();
extern void Sched_RunTask();

typedef struct {
    u8 pad0[0x118];
    u8 queue[0x1E8];
    s32 unk300;
    u8 pad304[0xC];
    s32 unk310;
    s32 unk314;
} Sc;

void Sched_HandleNotify(Sc *a0) {
    s32 sp3C = 0;
    s32 sp38 = 0;
    s32 sp34 = 0;
    s32 s0;

    if (func_80088070(a0->queue, &sp34, 0) != -1) {
        do {
            Sched_QueueTask(a0, sp34);
        } while (func_80088070(a0->queue, &sp34, 0) != -1);
    }
    if (a0->unk300 != 0 && a0->unk310 != 0) {
        Sched_Yield(a0, &sp3C);
    } else {
        s0 = ((a0->unk310 == 0) << 1) | (a0->unk314 == 0);
        if (Sched_Schedule(a0, &sp3C, &sp38, s0) != s0) {
            Sched_RunTask(a0, sp3C, sp38);
        }
    }
}
