#include "types.h"
#include "generated/code_funcs.h"

typedef struct {
    /* 0x00 */ void (*draw)(void *);
    /* 0x04 */ u8 pad4[0x20];
} GetItemEntry;

extern GetItemEntry D_801BBCA0[];

void GetItem_Draw(struct PlayState *play, s16 drawId) {
    D_801BBCA0[drawId].draw(play);
}
