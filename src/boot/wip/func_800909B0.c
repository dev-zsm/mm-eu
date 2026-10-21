// FLAGS: -O1 -g3 -mips2
#include "types.h"

extern s8 D_8009E9A0[];
s32 func_80089C90(void);
void func_80089CD4(void);
s32 func_8008AF10(s32, s8 *);
void func_80088070(s32, s32, s32);

s32 func_800909B0(s32 arg0, s32 arg1) {
    s8 *p;
    s32 i;
    s32 ret;
    s32 n;

    func_80089C90();
    p = D_8009E9A0;
    *(s32 *)&D_8009E9A0[0x3C] = 1;
    i = 0;
    if (arg1 > 0) {
        n = arg1 & 3;
        if (n != 0) {
            do {
                i++;
                *p = 0;
                p++;
            } while (n != i);
            if (i == arg1) {
                goto end;
            }
        }
        do {
            i += 4;
            p[0] = 0;
            p[1] = 0;
            p[2] = 0;
            p += 4;
            p[-1] = 0;
        } while (i != arg1);
    }
end:
    p[0] = 0xFD;
    p[1] = 0xFE;
    func_8008AF10(1, D_8009E9A0);
    func_80088070(arg0, 0, 1);
    ret = func_8008AF10(0, D_8009E9A0);
    func_80088070(arg0, 0, 1);
    func_80089CD4();
    return ret;
}
