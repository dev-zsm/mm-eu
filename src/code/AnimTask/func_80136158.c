#include "types.h"

typedef struct { s16 x, y, z; } V3s;
typedef struct {
    u8 flags;
    u8 count;
    u8 pad2[2];
    V3s *dst;
    V3s *src;
    u8 *map;
} Task;

extern s32 D_801ED334;

void AnimTask_CopyUsingMapInverted(s32 unused, Task *t) {
    Task *p = t;
    V3s *d;
    V3s *s;
    u8 *m;
    s32 i;

    if (!(t->flags & D_801ED334)) {
        d = t->dst;
        s = t->src;
        m = t->map;
        i = 0;
        if (t->count > 0) {
            do {
                if (!*m++) {
                    *d = *s;
                }
                i++;
                d++;
                s++;
            } while (i < p->count);
        }
    }
}
