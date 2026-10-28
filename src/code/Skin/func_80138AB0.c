#include "types.h"

typedef struct {
    u8 pad0[4];
    void *a;
    void *b;
} Ent;

typedef struct {
    u8 pad0[0x44];
    s32 count;
    Ent *ents;
    u8 sub[1];
} Skin;

extern void ZeldaArena_Free(void *);
extern void func_80137C80(void *, s32);

void Skin_Free(s32 a0, Skin *skin) {
    s32 i;

    if (skin->ents != 0) {
        for (i = 0; i < skin->count; i++) {
            if (skin->ents[i].a != 0) {
                ZeldaArena_Free(skin->ents[i].a);
                skin->ents[i].a = 0;
            }
            if (skin->ents[i].b != 0) {
                ZeldaArena_Free(skin->ents[i].b);
                skin->ents[i].b = 0;
            }
        }
        if (skin->ents != 0) {
            ZeldaArena_Free(skin->ents);
        }
        func_80137C80(skin->sub, a0);
    }
}
