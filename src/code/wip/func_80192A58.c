#include "types.h"

typedef struct {
    u8 pad0[8];
    void *unk8;
    s32 unkC;
    u8 pad10[0x14];
    u8 unk24[0x18];
    u8 unk3C[1];
} AsyncDmaRequest;

extern void Audio_InvalDCache(s32 a0, s32 a1);
extern void func_8008F3E0(void *a0, void *a1, s32 a2);
extern void func_80091460(void *a0, s32 a1, s32 a2);
extern void func_80087CB0(void *a0, s32 a1, s32 a2);

void AudioLoad_AsyncDmaRamUnloaded(AsyncDmaRequest *req, s32 size) {
    void *queue;

    size = (size + 0xF) & ~0xF;
    Audio_InvalDCache(req->unkC, size);
    queue = req->unk24;
    func_8008F3E0(queue, req->unk3C, 1);
    func_80091460(req->unk8, req->unkC, size);
    func_80087CB0(queue, 0, 0);
}
