// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct SchedTask {
    u8 pad0[4];
    s32 type;
    u8 pad8[8];
    u8 flags10;
    u8 pad11;
    s8 count12;
} SchedTask;

typedef struct {
    u8 pad0[0x318];
    s32 retraceCount;
    u8 pad31C[4];
    SchedTask *cur;
    SchedTask *next;
} Sched;

extern void func_80080778(void);
extern s32 func_80096670(void);
extern void func_801774E8(Sched *a, SchedTask *b);
extern void Sched_HandleNotify(Sched *a);

void Sched_HandleRetrace(Sched *sc) {
    s32 type;
    s32 v;
    s8 cnt;

    func_80080778();
    sc->retraceCount++;
    type = func_80096670();
    v = (sc->next != NULL) ? sc->next->type : 0;
    if (v == type) {
        if (sc->cur != NULL) {
            sc->cur->flags10 = 0;
        }
        if (sc->next != NULL) {
            sc->next->flags10 = 0;
        }
        sc->cur = sc->next;
        sc->next = NULL;
    }
    if (sc->cur != NULL) {
        cnt = sc->cur->count12;
        if (cnt > 0) {
            sc->cur->count12 = cnt - 1;
            cnt = sc->cur->count12;
        }
        if (cnt <= 0) {
            if (sc->next != NULL) {
                func_801774E8(sc, sc->next);
            }
        }
    }
    Sched_HandleNotify(sc);
}
