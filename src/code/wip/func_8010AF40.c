// FLAGS: -O2 -g3 -mips2
#include "types.h"
typedef struct { u8 pad0[0x124]; void *unk124; } Self;
void Actor_ChangeFocus(void *arg0);
s32 MsgEvent_FocusToSelf(void *a0, s64 a1, s32 a3) {
    Self *s = (Self *)a0; if (s->unk124 != NULL) { Actor_ChangeFocus(s->unk124); } return 0;
}
