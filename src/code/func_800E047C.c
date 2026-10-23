#include "types.h"
typedef struct { u32 a; u32 b; } Pair8;
extern Pair8 D_801BAD88;
s32 Collider_InitElementDamageInfoAT(void *a0, Pair8 *a1) {
    *a1 = D_801BAD88;
    return 1;
}
