// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x147];
    s8 itemAction;
    u8 pad148[0xB28 - 0x148];
    s16 unkB28;
    u8 padB2A[0xB9C - 0xB2A];
    f32 unkB9C[3];
} Player;

typedef struct {
    u8 pad0[0x1CCC];
    Player *player;
} Play;

extern void Math_Vec3f_Diff(f32 *a, f32 *b, f32 *out);

s32 Player_IsBurningStickInRange(Play *play, f32 *pos, f32 range, f32 yRange) {
    Player *player = play->player;
    f32 d[3];
    s32 pad[2];

    if (player->itemAction == 7 && player->unkB28 != 0) {
        Math_Vec3f_Diff(player->unkB9C, pos, d);
        return (d[2] * d[2] + d[0] * d[0] <= range * range) && (d[1] >= 0.0f) && (d[1] <= yRange);
    }
    return 0;
}
