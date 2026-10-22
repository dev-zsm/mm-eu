// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Obj {
    u8 pad0[0x24C];
    u8 unk24C;
    u8 pad24D[0x3];
    u64 unk250;
} Obj;

extern s32 D_80096D00;
extern u64 D_80096D08;
extern u64 osGetTime(void);
extern void IrqMgr_JamMesgToClients(Obj *a, u8 *b);
extern void osSetTimer(void *a, u64 b, s32 c, s32 d, void *e, s32 f);

void IrqMgr_HandlePreNMI(Obj *arg0) {
    u64 t;

    D_80096D00 = 1;
    arg0->unk24C = 1;
    t = osGetTime();
    arg0->unk250 = t;
    D_80096D08 = t;
    osSetTimer((u8 *)arg0 + 0x258, 0x141DD76, 0, 0, (u8 *)arg0 + 0x60, 0x29F);
    IrqMgr_JamMesgToClients(arg0, (u8 *)arg0 + 0x20);
}
