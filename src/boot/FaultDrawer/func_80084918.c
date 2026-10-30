// FLAGS: -O2 -g3 -mips2 -trapuv
#include "faultdrawer.h"
#include "fault.h"
#include "os_internal.h"
#include "os_pfs.h"

void FaultDrawer_Init(void) {
    D_80096D80 = &D_8009D0A0;
    bcopy(&D_80096D84, D_80096D80, sizeof(FaultDrawer));
    D_80096D80->fb = (u16 *)((D_80000318 | 0x80000000) + 0xFFFDA800);
}
