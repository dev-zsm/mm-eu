#include "types.h"

typedef struct {
    s16 count;
    u8 pad2[2];
    u8 tasks[50][0x40];
} AnimTaskQueue;

u8 *AnimTaskQueue_NewTask(AnimTaskQueue *queue, s32 type) {
    s16 n = queue->count;

    if (n >= 50) {
        return 0;
    }
    queue->count = n + 1;
    queue->tasks[n][0] = type;
    return queue->tasks[n];
}
