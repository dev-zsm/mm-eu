#include "types.h"
typedef struct { u8 type; u8 pad[3]; u8 data[0x3C]; } T;
typedef struct { s16 count; s16 pad; T tasks[1]; } Q;
extern void (*D_801C6970[])(s32, void *);
extern s32 D_801ED330;
extern s32 D_801ED334;
void AnimTaskQueue_Update(s32 play, Q *q) {
    T *t = q->tasks;
    while (q->count != 0) {
        D_801C6970[t->type](play, t->data);
        t++;
        q->count--;
    }
    D_801ED330 = 1;
    D_801ED334 = 0;
}
