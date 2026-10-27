// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Actor {
    u8 pad0[0x20];
    s16 halfDaysBits; /* 0x20 */
} Actor;

Actor *Actor_SpawnAsChildAndCutscene(void *actorCtx, void *play, s16 actorId, f32 posX, f32 posY, f32 posZ,
                                     s16 rotX, s16 rotY, s16 rotZ, s32 params, s32 csId, s32 halfDaysBits,
                                     Actor *parent);

Actor *Actor_SpawnAsChild(void *actorCtx, Actor *parent, void *play, s16 actorId, f32 posX, f32 posY, f32 posZ,
                          s16 rotX, s16 rotY, s16 rotZ, s32 params) {
    return Actor_SpawnAsChildAndCutscene(actorCtx, play, actorId, posX, posY, posZ, rotX, rotY, rotZ, params, -1,
                                         parent->halfDaysBits, parent);
}
