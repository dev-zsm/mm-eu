#include "types.h"

typedef struct {
    u8 b[8];
} Raw8;

typedef struct {
    u8 unk0;
    u8 pad1;
    Raw8 raw;
    s16 unkA;
} JntSphElementInit;

typedef struct {
    Raw8 raw;
    u8 pad8[8];
    f32 unk10;
    u8 unk14;
} JntSphElement;

extern f32 D_801D5650;

s32 Collider_SetJntSphElementDim(s32 arg0, JntSphElement *dest, JntSphElementInit *src) {
    dest->unk14 = src->unk0;
    dest->raw = src->raw;
    dest->unk10 = src->unkA * D_801D5650;
    return 1;
}
