#include "types.h"
typedef struct { u8 pad[0x12C]; s32 unk12C; } S;
extern S *SubS_FindActor(s32, s32, s32, s32);
extern f32 Actor_WorldDistXYZToActor(s32, S *);
S *EnHy_FindNearestDoor(s32 a0, s32 a1) {
    f32 best = 0.0f;
    S *res = 0;
    s32 i = 0;
    s32 first = 0;
    S *cur;
    f32 d;
    while (1) {
        cur = SubS_FindActor(a1, i, 10, 5);
        d = Actor_WorldDistXYZToActor(a0, cur);
        if (first == 0 || d < best) {
            res = cur;
            best = d;
            first = 1;
        }
        i = cur->unk12C;
        if (i == 0) break;
    }
    return res;
}
