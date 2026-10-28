#include "types.h"
typedef struct { s16 a; s16 b; } E;
extern E D_801BE5A0[11];
s32 Horse_IsValidSpawn(s16 a) {
    s32 i;
    for (i = 0; i < 11; i++) {
        if (a == D_801BE5A0[i].a) {
            return 1;
        }
    }
    return 0;
}
