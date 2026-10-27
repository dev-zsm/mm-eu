#include "types.h"

typedef struct { u8 pad0[0xA]; s16 ny; u8 padC[4]; } Poly;

extern void StaticLookup_AddPolyToSSList(void *a0, void *a1, Poly *polyList, s32 a3, s16 index);

void StaticLookup_AddPoly(u8 *lookup, void *a1, Poly *polyList, s32 a3, s16 index) {
    s32 ny = polyList[index].ny;

    if (ny >= 0x4000) {
        StaticLookup_AddPolyToSSList(a1, lookup, polyList, a3, index);
    } else if (ny < -0x6665) {
        StaticLookup_AddPolyToSSList(a1, lookup + 4, polyList, a3, index);
    } else {
        StaticLookup_AddPolyToSSList(a1, lookup + 2, polyList, a3, index);
    }
}
