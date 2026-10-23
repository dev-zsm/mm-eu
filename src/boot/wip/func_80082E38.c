// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

#define CHECK_BTN_ALL(state, combo) (~((state) | ~(combo)) == 0)

typedef struct {
    u16 button;
    s8 stickX;
    s8 stickY;
    u8 errNo;
} ContPad;

typedef struct {
    ContPad cur;
    ContPad prev;
    ContPad press;
    ContPad rel;
} Input;

typedef struct {
    u8 pad0[0x7CF];
    u8 exit;
    u8 pad7D0[0x7E4 - 0x7D0];
    Input padInput;
} FaultCtx;

extern FaultCtx *D_8009C220;
extern u8 D_80098C08[];

extern void Fault_Sleep(u32 ms);
extern void Fault_UpdatePadImpl(void);
extern void Fault_DrawMemDumpContents(char *title, u32 addr, u32 arg2);

void Fault_DrawMemDump(u32 pc, u32 sp, u32 cLeftJump, u32 cDownJump) {
    u32 addr = pc;
    s32 scrollCountdown;
    s32 off;
    Input *input = &D_8009C220->padInput;

    do {
        if (addr < 0x80000000) {
            addr = 0x80000000;
        }
        if (addr > 0x807FFF00) {
            addr = 0x807FFF00;
        }
        addr &= ~0xF;
        Fault_DrawMemDumpContents(D_80098C08, addr, 0);
        scrollCountdown = 600;
        while (D_8009C220->exit) {
            if (scrollCountdown == 0) {
                return;
            }
            scrollCountdown--;
            Fault_Sleep(0x10);
            Fault_UpdatePadImpl();
            if (CHECK_BTN_ALL(input->press.button, 0x20)) {
                D_8009C220->exit = 0;
            }
        }
        do {
            Fault_Sleep(0x10);
            Fault_UpdatePadImpl();
        } while (input->press.button == 0);
        if (CHECK_BTN_ALL(input->press.button, 0x1000)) {
            return;
        }
        off = 0x10;
        if (CHECK_BTN_ALL(input->cur.button, 0x8000)) {
            off = 0x100;
        }
        if (CHECK_BTN_ALL(input->cur.button, 0x4000)) {
            off <<= 8;
        }
        if (CHECK_BTN_ALL(input->press.button, 0x800)) {
            addr -= off;
        }
        if (CHECK_BTN_ALL(input->press.button, 0x400)) {
            addr += off;
        }
        if (CHECK_BTN_ALL(input->press.button, 8)) {
            addr = pc;
        }
        if (CHECK_BTN_ALL(input->press.button, 4)) {
            addr = sp;
        }
        if (CHECK_BTN_ALL(input->press.button, 2)) {
            addr = cLeftJump;
        }
        if (CHECK_BTN_ALL(input->press.button, 1)) {
            addr = cDownJump;
        }
    } while (!CHECK_BTN_ALL(input->press.button, 0x20));
    D_8009C220->exit = 1;
}
