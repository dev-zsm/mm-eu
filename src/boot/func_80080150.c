#include "types.h"
void func_800897D0(u32 a, u32 b);
void func_80080150(u32 start, u32 end) {
    if (start < end) {
        func_800897D0(start, end - start);
    }
}
