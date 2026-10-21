// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern s32 D_80098030;
extern u8 D_8009D2A0[];
extern u8 D_8009D2E0;
extern u8 D_8009D2E1;
extern u8 D_8009D308[];
extern u8 D_8009D320[];

s64 func_800905C0(void);
void func_8008F3E0(void *a0, void *a1, s32 a2);
void func_800942F0(void *a0, s64 a2, s64 a3, void *a4, void *a5);
void func_80088070(void *a0, void *a1, s32 a2);
void func_80089F08(u8 a0);
void func_80089E5C(u8 *a0, void *a1);
void func_80089C40(void);
s32 func_8008AF10(s32 a0, void *a1);

typedef struct {
    u8 a[0x18];
    u8 b[0x20];
    s64 c;
    s32 d;
    u8 e[4];
} Loc;

s32 func_80089D00(void *arg0, s32 arg1, s32 arg2) {
    Loc L;

    if (D_80098030 != 0) {
        return 0;
    }
    D_80098030 = 1;
    L.c = func_800905C0();
    if ((u64)L.c < 0x0165A0BC) {
        func_8008F3E0(L.a, L.e, 1);
        func_800942F0(L.b, (s64)0x0165A0BC - L.c, 0, L.a, L.e);
        func_80088070(L.a, L.e, 1);
    }
    D_8009D2E1 = 4;
    func_80089F08(0);
    func_8008AF10(1, D_8009D2A0);
    func_80088070(arg0, L.e, 1);
    L.d = func_8008AF10(0, D_8009D2A0);
    func_80088070(arg0, L.e, 1);
    func_80089E5C(arg1, arg2);
    D_8009D2E0 = 0;
    func_80089C40();
    func_8008F3E0(D_8009D308, D_8009D320, 1);
    return L.d;
}
