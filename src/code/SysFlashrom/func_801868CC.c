#include "types.h"
#include "generated/code_funcs.h"

extern u8 D_801D7AE8[];
extern u8 D_801F3650[];
extern void func_80083EAC();
extern void func_8008A780();
extern void func_8018819C();
extern void func_80088070();
s32 SysFlashrom_ExecWrite(s32 a0, s32 a1, s32 a2) {
    u8 sp40[0x18];
    s32 i;
    s32 r;
    s32 p;
    s32 q;
    if (SysFlashrom_IsInit() == 0) {
        return -1;
    }
    if (a1 & 0x7F) {
        func_80083EAC(D_801D7AE8, 0x113);
    }
    func_8008A780(a0, a2 << 7);
    i = 0;
    if (a2 != 0) {
        p = a0; q = a1; do { func_8018819C(sp40, 0, p, D_801F3650); func_80088070(D_801F3650, 0, 1); r = func_8018825C(q); i++;
            if (r != 0) {
                return r;
            }
            p += 0x80;
            q++;
        } while (i != a2);
    }
    return 0;
}
