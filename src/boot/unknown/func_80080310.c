// FLAGS: -O2 -g3 -mips2
#include "os_internal.h"
#include "dmamgr.h"

void func_80175DB0(void *arg);

void func_80080310(void *arg) {
    // matching: the volatile pointer forces the ROM's lui+addiu+lw 0(reg) access to the reset status
    volatile s32 *resetStatus = &D_80096D00;

    StackCheck_Init(&D_8009A7C0, D_8009A2C0, D_8009A2C0 + sizeof(D_8009A2C0), 0, 0x100, D_80098430);
    func_800817A4(&D_8009B390, &D_8009A7C0, 0x12, 1);
    if (*resetStatus == 0) {
        DmaMgr_Init();
        func_80080260();
        func_80175DB0(arg);
        DmaMgr_Stop();
    }
}
