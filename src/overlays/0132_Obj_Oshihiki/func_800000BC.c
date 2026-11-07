#include "types.h"

typedef struct {
    u8 pad[0x178];
    s32 v[5];
} A;

void ObjOshihiki_ResetFloors(A *a) {
    s32 i;

    for (i = 0; i < 5; i++) {
        a->v[i] = 50;
    }
}
