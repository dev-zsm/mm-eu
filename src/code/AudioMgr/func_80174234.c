#include "types.h"

extern void func_800897D0(void *, s32);
extern void func_8008F3E0(void *, void *, s32);
extern void func_80089FE0(void *, s32, void *, void *, s32, s32);
extern void func_80095950(void *);
extern void AudioMgr_ThreadEntry(void *);


void AudioMgr_Init(u8 *audioMgr, s32 stack, s32 stackSize, s32 pri, s32 a4, s32 a5) {
    func_800897D0(audioMgr, 0x2E0);
    *(s32 *)(audioMgr + 4) = a4;

    *(s32 *)audioMgr = a5;
    *(s32 *)(audioMgr + 0x60) = 0;
    func_8008F3E0(audioMgr + 0xF4, audioMgr + 0x10C, 1);
    func_8008F3E0(audioMgr + 0x64, audioMgr + 0x7C, 0x1E);
    func_8008F3E0(audioMgr + 0x110, audioMgr + 0x128, 1);
    func_80089FE0(audioMgr + 0x130, pri, AudioMgr_ThreadEntry, audioMgr, stack, stackSize);
    func_80095950(audioMgr + 0x130);
}
