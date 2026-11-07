#include "types.h"
extern u8 D_80920C4C[];
typedef struct { u8 pad[0x15C]; void *p; u8 pad2[0xC]; u8 a, b, c; } A;
void ObjSwitch_CrystalSwitchOnInit(A *s) { s->c = 0xFF; s->b = 0xFF; s->a = 0xFF; s->p = D_80920C4C; }
