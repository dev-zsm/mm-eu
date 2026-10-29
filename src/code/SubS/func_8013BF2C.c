#include "types.h"

typedef struct Act {
    u8 pad0[0x12C];
    struct Act *next;
} Act;

extern Act *SubS_FindActor(void *ctx, Act *prev, u8 cat, s16 type);
extern f32 D_801D68B0;
extern f32 Actor_WorldDistXYZToActor(Act *a, Act *b);

Act *SubS_FindNearestActor(Act *self, void *ctx, u8 cat, s16 type) {
    Act *cur = NULL;
    Act *best = NULL;
    f32 bestDist = D_801D68B0;
    s32 found = 0;
    Act *a;
    f32 d;

    while (1) {
        a = SubS_FindActor(ctx, cur, cat, type);
        if (a == NULL) {
            break;
        }
        if (a != self) {
            d = Actor_WorldDistXYZToActor(self, a);
            if (found == 0 || d < bestDist) {
                best = a;
                bestDist = d;
                found = 1;
            }
        }
        cur = a->next;
        if (cur == NULL) {
            break;
        }
    }
    return best;
}
