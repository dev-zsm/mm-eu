// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct EnAObj {
    u8 pad0[0x144];
    void (*unk144)(struct EnAObj *, void *);
    u8 pad148[0x148 - 0x148];
} EnAObj;

void Actor_SetFocus(void *, s32);
void CollisionCheck_SetOC(void *, void *, void *);

void EnAObj_Update(EnAObj *this, void *arg1) {
    this->unk144(this, arg1);
    Actor_SetFocus(this, 0x42340000);
    CollisionCheck_SetOC(arg1, (u8 *)arg1 + 0x18884, (u8 *)this + 0x148);
}
