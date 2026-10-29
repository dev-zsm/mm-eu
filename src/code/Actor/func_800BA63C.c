#include "types.h"

typedef struct Actor {
    u8 pad0[0x20];
    s16 flags;
    u8 pad22[0xFB];
    u8 unk11D;
    u8 pad11E[0xE];
    struct Actor *next;
} Actor;

typedef struct {
    u8 pad0[0xC];
    s16 mask;
} ActorCtx;

typedef struct {
    u8 pad0[0x1693C];
    s16 unk1693C;
} Play;

extern void func_80123A40();
extern Actor *Actor_Delete();
extern void Actor_Kill();
extern void Actor_Destroy();
extern void CollisionCheck_ClearContext();

void Actor_KillAllOnHalfDayChange(Play *play, ActorCtx *actx) {
    s32 i;
    u8 *p;
    Actor *a;


    for (i = 0, p = (u8 *)actx; i != 0x90; i += 0xC, p += 0xC) {
        a = *(Actor **)(p + 0x14);
        if (a != NULL) {
            do {
                if ((a->flags & actx->mask) == 0) {
                    func_80123A40(play, a);
                    if (a->unk11D == 0) {
                        a = Actor_Delete(actx, a, play);
                    } else {
                        Actor_Kill(a);
                        Actor_Destroy(a, play);
                        a = a->next;
                    }
                } else {
                    a = a->next;
                }
            } while (a != NULL);
        }
    }
    CollisionCheck_ClearContext(play, (u8 *)play + 0x18884);
    play->unk1693C = 0;
}
