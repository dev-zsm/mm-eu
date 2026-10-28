#include "types.h"
typedef struct { u8 pad0[4]; u32 unk4; } FE;
typedef struct { u8 pad0[4]; u8 req[0x20]; u8 mq[0x18]; u8 buf[4]; } Task;
extern Task *AnimTaskQueue_NewTask(void *, s32);
extern FE *func_80100304(s32);
extern void func_8008F3E0(void *, void *, s32);
extern void func_80080C54(void *, s32, u32, u32, u32, void *, u32);
extern u8 D_5E0C00[];
void AnimTaskQueue_AddLoadPlayerFrame(u8 *arg0, s32 arg1, s32 arg2, u32 arg3, s32 arg4) {
    Task *task;
    FE *e;
    void *q;
    task = AnimTaskQueue_NewTask(arg0 + 0x17104, 0);
    if (task != 0) {
        e = func_80100304(arg1);
        q = task->mq;
        func_8008F3E0(q, task->buf, 1);
        func_80080C54(task->req, arg4, (e->unk4 & 0xFFFFFF) + (arg3 * 6 + 2) * arg2 + (u32)D_5E0C00, arg3 * 6 + 2, 0, q, 0);
    }
}
