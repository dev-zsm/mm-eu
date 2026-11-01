#include "types.h"

typedef struct { u8 pad0[0x7978]; u8 rd; u8 wr; u8 unk797A; u8 pad[0x15]; void *queue; } Hdr;
extern Hdr D_801F84B0;
extern s32 D_801CE924;
extern s32 func_80087CB0(void *q, s32 msg, s32 flag);

s32 AudioThread_ScheduleProcessCmds(void) {
    s32 n;
    u8 rd = D_801F84B0.rd;
    u8 wr = D_801F84B0.wr;

    n = (u8)(rd - wr + 0x100);
    if (D_801CE924 < n) {
        D_801CE924 = n;
    }
    if (func_80087CB0(D_801F84B0.queue, (wr << 8) | rd, 0) == -1) {
        return -1;
    }
    D_801F84B0.wr = D_801F84B0.rd;
    return 0;
}
