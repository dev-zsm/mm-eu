#include "types.h"

typedef struct {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ u8 pad4[4];
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ u8 pad14[0x3C];
    /* 0x50 */ void *unk50;
    /* 0x54 */ s32 unk54;
} SchedTask; /* size = 0x58 */

typedef struct {
    u8 data[0x18];
} MesgQueue;

extern void func_8008F3E0(MesgQueue *, void **, s32);
extern void func_80087CB0(void *, SchedTask *, s32);
extern void Sched_SendNotifyMsg(void *);
extern void func_80088070(MesgQueue *, void *, s32);
extern u8 D_801EFB58[];
extern u8 D_801EFA40[];

void Sched_FlushTaskQueue(void) {
    SchedTask task;
    MesgQueue queue;
    void *msg;

    task.unk0 = 0;
    task.unk8 = 3;
    task.unk50 = &queue;
    task.unk54 = 0;
    task.unkC = 0;
    task.unk10 = 0;
    func_8008F3E0(&queue, &msg, 1);
    func_80087CB0(D_801EFB58, &task, 1);
    Sched_SendNotifyMsg(D_801EFA40);
    func_80088070(&queue, 0, 1);
}
