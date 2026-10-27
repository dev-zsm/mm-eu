#include "types.h"

typedef struct {
    /* 0x0000 */ u8 pad0[0x1E94];
    /* 0x1E94 */ s8 impactType;
    /* 0x1E95 */ u8 impactPriority;
    /* 0x1E96 */ u8 pad1E96[2];
    /* 0x1E98 */ f32 impactStrength;
    /* 0x1E9C */ u8 impactPos[12];
} PlayerImpact;

extern void Math_Vec3f_Copy(void *dest, void *src);

s32 Actor_SetPlayerImpact(PlayerImpact *player, s32 type, s32 priority, f32 strength, void *arg4) {
    if (player->impactPriority != 0 && strength < player->impactStrength) {
        return 0;
    }
    player->impactType = type;
    player->impactPriority = priority;
    player->impactStrength = strength;
    Math_Vec3f_Copy(player->impactPos, arg4);
    return 1;
}
