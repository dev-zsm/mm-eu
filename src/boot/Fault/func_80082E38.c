// FLAGS: -O2 -g3 -mips2 -trapuv
#include "fault.h"

void Fault_DrawMemDump(u32 pc, u32 sp, u32 cLeftJump, u32 cRightJump) {
    u32 addr = pc;
    s32 scrollCountdown;
    s32 off;
    Input *input = &D_8009C220->padInput[0];

    do {
        if (addr < 0x80000000) {
            addr = 0x80000000;
        }
        if (addr > 0x807FFF00) {
            addr = 0x807FFF00;
        }
        addr &= ~0xF;
        scrollCountdown = 0; /* matching: dead store, only for the scheduling */
        Fault_DrawMemDumpContents(D_80098C08, addr, 0);
        scrollCountdown = 600;
        while (D_8009C220->autoScroll) {
            if (scrollCountdown == 0) {
                return;
            }
            scrollCountdown--;
            Fault_Sleep(0x10);
            Fault_UpdatePadImpl();
            if (CHECK_BTN_ALL(input->press.button, BTN_L)) {
                D_8009C220->autoScroll = 0;
            }
        }
        do {
            Fault_Sleep(0x10);
            Fault_UpdatePadImpl();
        } while (input->press.button == 0);
        if (CHECK_BTN_ALL(input->press.button, BTN_START)) {
            return;
        }
        off = 0x10;
        if (CHECK_BTN_ALL(input->cur.button, BTN_A)) {
            off = 0x100;
        }
        if (CHECK_BTN_ALL(input->cur.button, BTN_B)) {
            off <<= 8;
        }
        if (CHECK_BTN_ALL(input->press.button, BTN_DUP)) {
            addr -= off;
        }
        if (CHECK_BTN_ALL(input->press.button, BTN_DDOWN)) {
            addr += off;
        }
        if (CHECK_BTN_ALL(input->press.button, BTN_CUP)) {
            addr = pc;
        }
        if (CHECK_BTN_ALL(input->press.button, BTN_CDOWN)) {
            addr = sp;
        }
        if (CHECK_BTN_ALL(input->press.button, BTN_CLEFT)) {
            addr = cLeftJump;
        }
        if (CHECK_BTN_ALL(input->press.button, BTN_CRIGHT)) {
            addr = cRightJump;
        }
    } while (!CHECK_BTN_ALL(input->press.button, BTN_L));
    D_8009C220->autoScroll = 1;
}
