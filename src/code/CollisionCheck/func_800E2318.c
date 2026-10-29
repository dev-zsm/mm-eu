#include "types.h"

typedef struct {
    u8 pad0[0x138];
    void *unk138;
} Act;
typedef struct {
    Act *actor;
    u8 pad4[0x11];
    u8 shape;
} Col;
typedef struct {
    s16 count;
    u16 flags;
    Col *colAt[50];
} CC;
extern s32 func_8016B1A4(void *);
extern void (*D_801BAE68[])(void *, Col *);
s32 CollisionCheck_SetAT(void *play, CC *check, Col *collider) {
    s32 index;
    Act *new_var;
    if (func_8016B1A4(play) != 0) {
        return -1;
    }
    D_801BAE68[collider->shape](play, collider);
    new_var = collider->actor;
    if ((new_var != ((void *) 0)) && (collider->actor->unk138 == ((void *) 0))) {
        return -1;
    }
    if (check->count >= 50) {
        return -1;
    }
    if (check->flags & 1) {
        return -1;
    }
    index = check->count;
    check->colAt[check->count] = collider;
    check->count++;
    return index;
}
