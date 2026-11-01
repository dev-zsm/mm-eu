#include "types.h"
#include "code_funcs.h"

extern void func_80091460(void *dst, void *src, s32 size);

void func_80137CCC(u8 *entry, void *src, void *dst) {
    func_80091460(dst, src, *entry * 6);
}
