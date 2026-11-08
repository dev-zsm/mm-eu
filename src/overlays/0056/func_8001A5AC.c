#include "types.h"
#include "generated/overlays/0056.h"
extern u8 D_8085CCCC[];
void func_80846B80(s32, s32, f32, s16);
void func_8082D8D4();
void func_80847610();
void func_8001A5AC(s32 a, s32 b, f32 c, s16 d) {
    func_80846B80(a, b, c, d);
    func_8082D8D4(a, D_8085CCCC);
    func_80847610(a);
}
