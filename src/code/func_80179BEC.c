// FLAGS: -O1 -g3 -mips2
#include "types.h"

extern u8 D_80000500[];
extern u8 D_807DA800[];
extern u8 D_80780000[];
extern u8 *D_801F341C;
extern u8 *D_801F3420;
extern u8 *D_801F3434;
extern u8 *D_801F3438;
extern void func_80179930(void);
void func_80179BEC(void) {
    D_801F341C = D_80000500;
    do { D_801F3420 = D_807DA800; D_801F3434 = D_80000500; } while (0);
    D_801F3438 = D_80780000;
    func_80179930();
}
