// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x1C];
    s16 unk1C;
} EnAObj;

void Gfx_DrawDListOpa(void *, s32, void *, void *);
extern s32 D_801AED70[];

void EnAObj_Draw(EnAObj *arg0, void *arg1) {
    Gfx_DrawDListOpa(arg1, D_801AED70[arg0->unk1C], arg1, arg0);
}
