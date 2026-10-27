#include "types.h"

typedef struct {
    char pad0[0x12];
    s8 unk12;
} Task;

typedef struct {
    char pad0[0x320];
    Task *curTask;
    s32 nextFramebuffer;
} Scheduler;

typedef struct {
    char pad0[0xC];
    s32 framebuffer;
} TaskRequest;

void func_801774E8(Scheduler *sc, s32 fb);

void Sched_SetNextFramebufferFromTask(Scheduler *sc, TaskRequest *req) {
    sc->nextFramebuffer = req->framebuffer;
    if (sc->curTask == NULL || sc->curTask->unk12 <= 0) {
        func_801774E8(sc, sc->nextFramebuffer);
    }
}
