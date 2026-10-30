// FLAGS: -O2 -g3
#include "os_internal.h"
#include "os_sp.h"

void func_80081880(void) {
    FaultDrawer_DrawText(0x50, 0xC8, D_80098510, IO_READ(SP_STATUS_REG));
    FaultDrawer_DrawText(0x28, 0xB8, D_80098520, D_800998A0);
    FaultDrawer_DrawText(0x38, 0xC0, D_80098534, D_800998AC);
}
