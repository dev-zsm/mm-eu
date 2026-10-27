#include "types.h"

typedef struct Actor Actor;
struct Actor {
    u8 pad0[0x1E];
    s8 unk1E;
    u8 pad1F[0x144 - 0x1F];
    void (*unk144)(Actor *, s32);
};

typedef struct {
    u8 pad0[0x17D88];
    u8 objectCtx;
} PlayState;

extern void func_800A692C(Actor *, s32);
extern s32 Object_GetSlot(u8 *objectCtx, s32 arg1, PlayState *play);
extern s32 Object_IsLoaded(u8 *objectCtx, s32 arg1);

void EnItem00_WaitForHeartObject(Actor *actor, PlayState *play) {
    s32 index = Object_GetSlot(&play->objectCtx, 0x96, play);

    if (Object_IsLoaded(&play->objectCtx, index) != 0) {
        actor->unk1E = index;
        actor->unk144 = func_800A692C;
    }
}
