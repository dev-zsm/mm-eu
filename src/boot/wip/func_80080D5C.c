// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern u8 D_1A8D0[];
extern u8 D_20C20[];
extern s16 D_8009B68C;
extern u8 D_8009B690[];
extern u8 D_8009B6A8[];
extern u8 D_8009B670[];
extern u8 D_8009B8D8[];
extern u8 D_8009BDD8[];
extern u8 D_80098494[];
extern u8 D_8009B728[];

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
} BootEntry;

extern BootEntry D_8009FC80[];

void func_800807E0(void *a, void *b, u32 c);
void osCreateMesgQueue(void *a, void *b, u32 c);
void StackCheck_Init(void *a, void *b, void *c, s32 d, s32 e, void *f);
void osCreateThread(void *a, s32 b, void *c, s32 d, void *e, s32 f);
void osStartThread(void *a);
void DmaMgr_ThreadEntry(void);
void DmaMgr_Init(void) {
    BootEntry *e;
    BootEntry *p;
    s32 i;

    func_800807E0(D_1A8D0, D_8009FC80, D_20C20 - D_1A8D0);
    e = D_8009FC80;
    i = 0;
    if (e->unk4 != 0) {
        p = e;
        do {
            p++;
            i++;
        } while (p->unk4 != 0);
    }
    D_8009B68C = i;
    osCreateMesgQueue(D_8009B690, D_8009B6A8, 0x20);
    StackCheck_Init(D_8009B670, D_8009B8D8, D_8009BDD8, 0, 0x100, D_80098494);
    osCreateThread(D_8009B728, 0x12, DmaMgr_ThreadEntry, 0, D_8009BDD8, 0x11);
    osStartThread(D_8009B728);
}
