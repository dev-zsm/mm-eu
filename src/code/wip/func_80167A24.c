// FLAGS: -O2 -g3 -mips2
#include "types.h"
typedef struct { u8 pad[0x28]; f32 unk28; } Player;
typedef struct { f32 x, y, z; } V3;
typedef struct {
    u8 pad0[0x830];
    u8 colCtx[0x1CCC - 0x830];
    Player *player;
} Play;
s32 BgCheck_GetWaterSurface(Play *, void *, f32, f32, f32 *, s32 *, s32 *);
s32 WaterBox_GetLightSettingIndex(void *, s32);
f32 Play_GetWaterSurface(Play *play, V3 *pos, s32 *lightIdx) {
    Player *pl;
    f32 y;
    s32 sp34;
    s32 sp30;
    void *col;
    pl = play->player;
    y = pl->unk28;
    col = play->colCtx;
    if (BgCheck_GetWaterSurface(play, col, pos->x, pos->z, &y, &sp34, &sp30) == 0) {
        return -32000.0f;
    }
    if (y < pos->y) {
        return -32000.0f;
    }
    *lightIdx = WaterBox_GetLightSettingIndex(col, sp34);
    return y;
}
