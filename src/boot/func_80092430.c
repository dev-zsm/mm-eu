// FLAGS: -O1 -g0 -mips2
#include "types.h"

extern s32 D_8009E980;
extern s32 D_8009E984;

typedef struct {
    s32 hi;
    s32 lo;
} OSTime;

void osSetTime(OSTime t) {
    D_8009E980 = t.hi;
    D_8009E984 = t.lo;
}
