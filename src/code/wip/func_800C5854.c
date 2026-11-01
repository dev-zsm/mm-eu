#include "types.h"

typedef struct {
    s16 max;
    s16 count;
    void *tbl;
    void *next;
} SSNodeList;

extern u8 D_801E52C0[];
extern u8 D_801E5310[];
extern u8 D_801D4CB0[];
extern u8 D_801D4CF4[];
extern void func_80087A44(u8 *a, u8 *b, ...);
extern void func_80083E54(u8 *a, u8 *b);
extern void *THA_AllocTailAlign(s32 a, s32 b, s32 c);
extern void *THA_AllocTailAlign16(s32 a, s32 b);

void SSNodeList_Alloc(s32 arg0, SSNodeList *arg1, s32 arg2, s32 arg3) {
    s32 a;

    arg1->max = arg2;
    arg1->count = 0;
    a = arg0 + 0x74;
    { void *t = THA_AllocTailAlign(a, arg2 * 4, -2); arg1->tbl = t; }
    arg1->next = THA_AllocTailAlign16(a, arg3);
    if (arg1->next == 0) {
        func_80087A44(D_801E52C0, D_801D4CB0);
        func_80087A44(D_801E5310, D_801D4CF4, arg2, arg3);
        func_80083E54(D_801E52C0, D_801E5310);
    }
}
