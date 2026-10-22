// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct { u8 pad0[0x800]; s32 unk800[4]; s16 unk810; } Play;

void Camera_Copy(s32, s32, s16, Play *);

void Play_CopyCamera(Play *arg0, s16 arg1, s16 arg2) {
    s16 var_v0;
    s16 var_v1;

    if (arg2 == -1) {
        var_v1 = arg0->unk810;
    } else {
        var_v1 = arg2;
    }
    if (arg1 == -1) {
        var_v0 = arg0->unk810;
    } else {
        var_v0 = arg1;
    }
    Camera_Copy(arg0->unk800[var_v0], arg0->unk800[var_v1], arg2, arg0);
}
