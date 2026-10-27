#include "types.h"

typedef struct {
    u8 pad0[0x33C];
    void *unk33C;
    u32 unk340;
    u32 unk344;
} Sub12F4;

typedef struct {
    u8 pad0[0x169E8];
    Sub12F4 unk169E8;
} Play12F4;

extern u8 D_A62000[];
extern u8 D_A87C00[];

void *ZeldaArena_Malloc(u32);
void func_80121220(Play12F4 *, s32);

void func_801212F4(Play12F4 *play) {
    Sub12F4 *s = &play->unk169E8;

    /* u32 casts only fix instruction scheduling */
    s->unk340 = (u32)D_A62000;
    s->unk344 = (u32)D_A87C00 - (u32)D_A62000;
    if (s->unk33C == NULL) {
        s->unk33C = ZeldaArena_Malloc(s->unk344);
    }
    func_80121220(play, 0);
}
