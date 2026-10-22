// FLAGS: -O2 -g3 -mips2
#include "types.h"

void osCreateMesgQueue(void *a, void *b, u32 c);
s32 DmaMgr_RequestAsync(void *a, s32 b, s32 c, s32 d, s32 e, void *f, s32 g);
void osRecvMesg(void *a, u32 b, u32 c);

// Starts a transfer through DmaMgr_RequestAsync with a temporary one-slot queue and waits for
// its completion message (likely osCreateMesgQueue + osRecvMesg, libultra). Returns -1
// if the transfer could not be started, 0 otherwise. The meaning of the three
// arguments is guessed (device address, RAM address, size); not confirmed.
s32 DmaMgr_RequestSync(s32 dev_addr, s32 ram_addr, s32 size) {
    u8 io_mesg[0x20];
    u8 queue[0x18];
    u8 msg[0x4];
    s32 ret;

    osCreateMesgQueue(queue, msg, 1);
    ret = DmaMgr_RequestAsync(io_mesg, dev_addr, ram_addr, size, 0, queue, 0);
    if (ret == -1) {
        return ret;
    }
    osRecvMesg(queue, 0, 1);
    return 0;
}
