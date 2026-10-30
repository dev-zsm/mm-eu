#include "os_internal.h"

void func_80080150(void *start, void *end) {
    if (start < end) {
        bzero(start, (u32)end - (u32)start);
    }
}
