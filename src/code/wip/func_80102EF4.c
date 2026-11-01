// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u16 id;
    u8 pad2[6];
    u16 flags;
} Ent;

extern void MapDisp_GetMapTexDim(Ent *, s32 *, s32 *, Ent *);
extern void MapData_GetMapTexOffset(u16, s32 *, s32 *, Ent *);

void MapDisp_GetMapOffset(Ent *e, s32 *x, s32 *y) {
    s32 w;
    s32 h;

    if (e->id == 0xFFFF) {
        *x = 0;
        *y = 0;
        return;
    }
    MapDisp_GetMapTexDim(e, &w, &h, e);
    MapData_GetMapTexOffset(e->id, x, y, e);
    if (e->flags & 1) {
        *x = w / 2 - *x + w / 2;
    }
    if (e->flags & 2) {
        *y = h / 2 - *y + h / 2;
    }
}
