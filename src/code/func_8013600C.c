#include "types.h"

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

typedef struct {
    u8 flags;
    u8 count;
    u8 pad2[2];
    Vec3s *dst;
    Vec3s *src;
} AnimTaskCopy;

extern u32 D_801ED334;

void AnimTask_Copy(void *play, AnimTaskCopy *taskArg) {
    AnimTaskCopy *task = taskArg; // extra copy: only to match the ROM register allocation
    s32 i;
    Vec3s *dst;
    Vec3s *src;

    if (!(task->flags & D_801ED334)) {
        dst = task->dst;
        src = task->src;
        for (i = 0; i < task->count; i++) {
            *dst++ = *src++;
        }
    }
}
