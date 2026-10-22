// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    s32 init;
    void *p04;
    void *p08;
    void *p0C;
    s32 p10;
    s32 p14;
    s32 p18;
} Ctx95440;

typedef struct {
    u16 kind;
    u8 flag;
    u8 pad;
    s32 val;
} Ent95440;

extern Ctx95440 D_800983A0;
extern s32 D_800983BC;
extern u8 D_8009FC10[];
extern u8 D_8009FC28[];
extern u8 D_8009FC40[];
extern u8 D_8009FC58[];
extern u8 D_8009EA60[];

void __osTimerServicesInit(void);
void osCreateMesgQueue(void *a, void *b, s32 c);
void osSetEventMesg(s32 a, void *b, void *c);
s32 osGetThreadPri(s32 a);
s32 osSetThreadPri(s32 a, s32 b);
s32 __osDisableInt(void);
void osCreateThread(void *a, s32 b, void *c, Ctx95440 *d, void *e, s32 f);
void __osViInit(void);
void osStartThread(void *a);
void __osRestoreInt(s32 a);
void viMgrMain(s32 a);

void osCreateViManager(s32 n) {
    Ctx95440 *s;
    Ent95440 *e1;
    Ent95440 *e2;
    s32 h;
    s32 ret;

    s = &D_800983A0;
    if (s->init != 0) {
        return;
    }
    __osTimerServicesInit();
    D_800983BC = 0;
    osCreateMesgQueue(D_8009FC10, D_8009FC28, 5);
    e1 = (Ent95440 *)&D_8009FC40;
    e2 = (Ent95440 *)&D_8009FC58;
    e1->kind = 0xD;
    e1->flag = 0;
    e1->val = 0;
    e2->kind = 0xE;
    e2->flag = 0;
    e2->val = 0;
    osSetEventMesg(7, D_8009FC10, e1);
    osSetEventMesg(3, D_8009FC10, e2);
    ret = -1;
    if (osGetThreadPri(0) < n) {
        ret = osSetThreadPri(0, n);
    }
    h = __osDisableInt();
    s->init = 1;
    s->p04 = D_8009EA60;
    s->p08 = D_8009FC10;
    s->p0C = D_8009FC10;
    s->p10 = 0;
    s->p14 = 0;
    s->p18 = 0;
    osCreateThread(D_8009EA60, 0, viMgrMain, s, D_8009FC10, n);
    __osViInit();
    osStartThread(D_8009EA60);
    __osRestoreInt(h);
    if (ret != -1) {
        osSetThreadPri(0, ret);
    }
}
