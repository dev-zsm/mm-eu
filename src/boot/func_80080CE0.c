// FLAGS: -O2 -g3 -mips2
#include "types.h"

void func_8008F3E0(void *a, void *b, u32 c);
s32 func_80080C54(void *a, s32 b, s32 c, s32 d, s32 e, void *f, s32 g);
void func_80088070(void *a, u32 b, u32 c);

// Starts a transfer through func_80080C54 with a temporary one-slot queue and waits for
// its completion message (likely osCreateMesgQueue + osRecvMesg, libultra). Returns -1
// if the transfer could not be started, 0 otherwise. The meaning of the three
// arguments is guessed (device address, RAM address, size); not confirmed.
s32 func_80080CE0(s32 dev_addr, s32 ram_addr, s32 size) {
    u8 io_mesg[0x20];
    u8 queue[0x18];
    u8 msg[0x4];
    s32 ret;

    func_8008F3E0(queue, msg, 1);
    ret = func_80080C54(io_mesg, dev_addr, ram_addr, size, 0, queue, 0);
    if (ret == -1) {
        return ret;
    }
    func_80088070(queue, 0, 1);
    return 0;
}
