#include "types.h"

typedef struct {
    u8 padEC[0xEC];
    u8 unkEC[0xC];
    s32 unkF8;
} Obj;

extern void Actor_CullingVolumeTest(s32, s32, u8 *, s32);

void Actor_CullingCheck(s32 arg0, Obj *arg1) {
    Actor_CullingVolumeTest(arg0, (s32)arg1, arg1->unkEC, arg1->unkF8);
}
