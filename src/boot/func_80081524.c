// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Obj {
    u8 pad0[0x24C];
    u8 unk24C;
} Obj;

extern volatile s32 D_80096D00;
extern void IrqMgr_SendMesgToClients(Obj *a, u8 *b);
extern void osSetTimer(void *a, u64 b, u64 c, void *e, void *f);

void IrqMgr_HandlePRENMI450(Obj *arg0) {
    D_80096D00 = 2;
    arg0->unk24C = 2;
    osSetTimer((u8 *)arg0 + 0x258, 0x15752A, 0, (u8 *)arg0 + 0x60, (void *)0x2A0);
    IrqMgr_SendMesgToClients(arg0, (u8 *)arg0 + 0x40);
}
