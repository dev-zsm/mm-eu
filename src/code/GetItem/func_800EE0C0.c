#include "types.h"

typedef struct {
    /* 0x00 */ void (*draw)(void *);
    /* 0x04 */ u8 pad4[0x20];
} GetItemEntry;

extern GetItemEntry D_801BBCA0[];

void GetItem_Draw(void *arg0, s16 index) {
    D_801BBCA0[index].draw(arg0);
}
