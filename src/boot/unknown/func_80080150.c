#include "types.h"
void bzero(u32 a, u32 b);
void func_80080150(u32 start, u32 end) {
    if (start < end) {
        bzero(start, end - start);
    }
}
