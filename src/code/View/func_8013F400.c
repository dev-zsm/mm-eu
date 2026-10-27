// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3s32;

typedef struct {
    u8 pad0[0x28];
    Vec3s32 unk28;
    Vec3s32 unk34;
    Vec3s32 unk40;
} ViewLook;

void View_LookAtUnsafe(ViewLook *arg0, Vec3s32 *arg1, Vec3s32 *arg2, Vec3s32 *arg3) {
    arg0->unk28 = *arg1;
    arg0->unk34 = *arg2;
    arg0->unk40 = *arg3;
}
