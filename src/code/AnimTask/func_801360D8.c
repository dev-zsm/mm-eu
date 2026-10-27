// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    s16 x, y, z;
} Vec3s;

typedef struct {
    u8 group;
    u8 vecCount;
    Vec3s *dest;
    Vec3s *src;
    u8 *limbCopyMap;
} AnimTaskCopyUsingMap;

extern u32 D_801ED334;

void AnimTask_CopyUsingMap(void *play, void *data) {
    AnimTaskCopyUsingMap *task = data;
    Vec3s *dest;
    Vec3s *src;
    u8 *limbCopyMap;
    s32 i;

    if (!(task->group & D_801ED334)) {
        dest = task->dest;
        src = task->src;
        limbCopyMap = task->limbCopyMap;
        for (i = 0; i < task->vecCount; i++) {
            if (*limbCopyMap++) {
                *dest = *src;
            }
            dest++;
            src++;
        }
    }
}
