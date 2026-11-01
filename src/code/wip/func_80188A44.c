#include "types.h"

typedef struct {
    /* 0x00 */ u8 pad0[0xD8];
    /* 0xD8 */ u8 flags;
    /* 0xD9 */ u8 padD9[5];
    /* 0xDE */ u8 unkDE;
    /* 0xDF */ u8 padDF[0x19];
} Elem; /* size 0xF8 */

typedef struct {
    /* 0x0000 */ u8 pad0[0x14];
    /* 0x0014 */ u8 (*tbl)[0x20];
    /* 0x0018 */ u8 pad18[0x28B8 - 0x18];
    /* 0x28B8 */ s32 count;
    /* 0x28BC */ u8 pad28BC[0x445C - 0x28BC];
    /* 0x445C */ Elem *elems;
} Ctx;

extern Ctx D_801F84B0;

void func_80188A44(s32 arg) {
    s32 i;
    s32 off = D_801F84B0.count * arg;

    for (i = 0; i < D_801F84B0.count; i++) {
        Elem *e = &D_801F84B0.elems[i];
        u8 *t = D_801F84B0.tbl[off + i];

        if (*(s32 *)&e->flags < 0) {
            e->flags &= ~0x40;
        } else {
            *t &= ~0x80;
        }
        e->unkDE = 0;
    }
}
