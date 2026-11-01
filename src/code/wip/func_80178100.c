#include "types.h"

typedef struct {
    /* 0x000 */ u8 pad0[4];
    /* 0x004 */ s32 flags;
} Task;

typedef struct {
    /* 0x000 */ u8 pad0[0x310];
    /* 0x310 */ Task *curRSPTask;
    /* 0x314 */ Task *curRDPTask;
} Sched;

extern u8 D_801D78F0[];
extern u64 D_801F3348;
extern u64 D_801F33A0;
extern void func_8008198C(void *);
extern u64 func_800905C0(void *);
extern s32 Sched_Schedule(Sched *, Task **, Task **, s32);
extern void Sched_TaskComplete(Sched *, Task *);
extern void Sched_RunTask(Sched *, Task *, Task *, s32);

void Sched_HandleRDPDone(Sched *sc) {
    Task *spec;
    Task *dpec;
    s32 state;
    Task *curTask;

    spec = NULL;
    dpec = NULL;
    if (sc->curRDPTask == NULL) {
        func_8008198C(D_801D78F0);
        return;
    }
    D_801F33A0 = func_800905C0(D_801D78F0) - D_801F3348;
    curTask = sc->curRDPTask;
    sc->curRDPTask = NULL;
    curTask->flags &= ~1;
    Sched_TaskComplete(sc, curTask);
    state = ((sc->curRSPTask == NULL) << 1) | (sc->curRDPTask == NULL);
    if (Sched_Schedule(sc, &spec, &dpec, state) != state) {
        Sched_RunTask(sc, spec, dpec, state);
    }
}
