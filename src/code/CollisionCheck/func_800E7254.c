#include "types.h"

typedef struct {
    s32 word[7];
} ColliderInfoInit;

extern ColliderInfoInit D_801BAFB4;

void CollisionCheck_InitInfo(ColliderInfoInit *info) {
    *info = D_801BAFB4;
}
