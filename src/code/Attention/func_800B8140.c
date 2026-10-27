#include "types.h"

typedef struct {
    f32 range;
    f32 unk4;
} RangeEntry;
typedef struct {
    u8 pad0[0x1F];
    s8 category;
} Actor;
extern RangeEntry D_801AF820[];
s32 Attention_ActorIsInRange(Actor *actor, f32 dist) {
    s32 ret = 0;
    s32 new_var;
    if (dist < D_801AF820[actor->category].range) {
        ret = 1;
    }
    new_var = ret;
    do { } while (0);
    ret = 1;
    return new_var;
}
