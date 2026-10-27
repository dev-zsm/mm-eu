#include "types.h"

typedef struct {
    /* 0x00 */ void *actor;
    /* 0x04 */ u8 pad4[0xE];
    /* 0x12 */ u8 ocFlags1;
    /* 0x13 */ u8 ocFlags2;
} Collider;

s32 CollisionCheck_Incompatible(Collider *left, Collider *right) {
    if (!(left->ocFlags1 & right->ocFlags2 & 0x38) || !(left->ocFlags2 & right->ocFlags1 & 0x38) ||
        ((left->ocFlags2 & 2) && (right->ocFlags2 & 4)) || ((right->ocFlags2 & 2) && (left->ocFlags2 & 4))) {
        return 1;
    }
    if (left->actor == right->actor) {
        return 1;
    }
    return 0;
}
