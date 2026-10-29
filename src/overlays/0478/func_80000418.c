#include "types.h"

typedef struct {
    s32 x[7];
} Entry1C;

extern Entry1C D_801E6FF0[];

s32 func_80000418(s32 a0) {
    return D_801E6FF0[((s16 *)a0)[0xA4 / 2]].x[3] & 7;
}
