// FLAGS: -O2 -g0
#include "types.h"

typedef struct Ctx {
    s32 unk0;
    void *unk4;
    void *unk8;
    void *unkC;
    void *unk10;
    void *unk14;
    void *unk18;
} Ctx;

extern Ctx D_80098060;
extern s32 D_80098090;
extern u8 D_8009D5F0[];
extern u8 D_8009E7A0[];
extern u8 D_8009E7B8[];
extern u8 D_8009E7C8[];

extern void osCreateMesgQueue(void *a, void *b, s32 c);
extern void __osPiCreateAccessQueue(void);
extern void osSetEventMesg(s32 a, void *b, u32 c);
extern s32 osGetThreadPri(s32 a);
extern void osSetThreadPri(s32 a, s32 b);
extern s32 __osDisableInt(void);
extern void __osRestoreInt(s32 a);
extern void osStartThread(void *a);
extern void osCreateThread(void *a, s32 b, void *c, void *d, void *e, s32 f);
extern void __osPiRawStartDma(void);
extern void __osDevMgrMain(void);
extern void __osEPiRawStartDma(void);

void osCreatePiManager(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 sp2C;
    s32 sp28;
    s32 temp_v0;

    if (D_80098060.unk0 == 0) {
        osCreateMesgQueue((void *)a1, (void *)a2, a3);
        osCreateMesgQueue(D_8009E7A0, D_8009E7B8, 1);
        if (D_80098090 == 0) {
            __osPiCreateAccessQueue();
        }
        osSetEventMesg(8, D_8009E7A0, 0x22222222);
        sp28 = -1;
        temp_v0 = osGetThreadPri(0);
        if (temp_v0 < a0) {
            sp28 = temp_v0;
            osSetThreadPri(0, a0);
        }
        sp2C = __osDisableInt();
        D_80098060.unk0 = 1;
        D_80098060.unk8 = (void *)a1;
        D_80098060.unk4 = D_8009D5F0;
        D_80098060.unkC = D_8009E7A0;
        D_80098060.unk10 = D_8009E7C8;
        D_80098060.unk14 = (void *)__osPiRawStartDma;
        D_80098060.unk18 = (void *)__osEPiRawStartDma;
        osCreateThread(D_8009D5F0, 0, (void *)__osDevMgrMain, &D_80098060, D_8009E7A0, a0);
        osStartThread(D_8009D5F0);
        __osRestoreInt(sp2C);
        if (sp28 != -1) {
            osSetThreadPri(0, sp28);
        }
    }
}
