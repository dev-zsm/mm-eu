#include "types.h"
extern s16 D_801C00A0;
extern s16 D_801C00A4;
extern s16 D_801C00A8;
extern void MapDisp_DrawMinimap();
void Map_DrawMinimap(s32 a0) {
    MapDisp_DrawMinimap(a0, D_801C00A0, D_801C00A4, D_801C00A8);
}
