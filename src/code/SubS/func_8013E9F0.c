#include "types.h"

typedef struct Fn8013E9F0Act {
    s16 id;
    u8 pad2[0x12A];
    struct Fn8013E9F0Act *next;
} Fn8013E9F0Act;

typedef struct {
    Fn8013E9F0Act *first;
    u8 pad4[8];
} Fn8013E9F0List;

typedef struct {
    u8 pad0[0x1CB4];
    Fn8013E9F0List lists[1];
} Fn8013E9F0Ctx;

typedef s32 (*Fn8013E9F0Pred)(Fn8013E9F0Ctx *, s32, Fn8013E9F0Act *, s32);

Fn8013E9F0Act *SubS_FindActorCustom(Fn8013E9F0Ctx *play, s32 arg1, Fn8013E9F0Act *start, u8 cat, s16 id, s32 aux,
                             Fn8013E9F0Pred pred) {
    Fn8013E9F0Act *iter = start;

    if (start == NULL) {
        iter = play->lists[cat].first;
    }
    while (iter != NULL &&
           (id != iter->id || (id == iter->id && (pred == NULL || (pred != NULL && pred(play, arg1, iter, aux) == 0))))) {
        iter = iter->next;
    }
    return iter;
}
