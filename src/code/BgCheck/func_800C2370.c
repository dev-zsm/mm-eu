#include "types.h"
typedef struct { f32 x, y, z; } V3;
typedef struct { s32 x, y, z; } V3i;
typedef struct {
    u8 pad0[4];
    V3 minPos;
    u8 pad10[0xC];
    V3i sub;
    u8 pad28[0x34 - 0x28];
    V3 inv;
} Lk;
void BgCheck_GetStaticLookupIndicesFromPos(Lk *lk, V3 *pos, V3i *idx) {
    idx->x = (pos->x - lk->minPos.x) * lk->inv.x;
    idx->y = (pos->y - lk->minPos.y) * lk->inv.y;
    idx->z = (pos->z - lk->minPos.z) * lk->inv.z;
    if (idx->x < 0) {
        idx->x = 0;
    } else if (idx->x >= lk->sub.x) {
        idx->x = lk->sub.x - 1;
    }
    if (idx->y < 0) {
        idx->y = 0;
    } else if (idx->y >= lk->sub.y) {
        idx->y = lk->sub.y - 1;
    }
    if (idx->z < 0) {
        idx->z = 0;
    } else if (idx->z >= lk->sub.z) {
        idx->z = lk->sub.z - 1;
    }
}
