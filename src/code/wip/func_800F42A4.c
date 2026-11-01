#include "types.h"

// Unaligned big-endian halfword read: combine the two aligned halfwords around ptr.
u16 Jpeg_GetUnalignedU16(u8 *ptr) {
    if (((s32)ptr & 1) == 0) {
        return *(u16 *)ptr;
    }
    return (((ptr[0] | (ptr[-1] << 8)) << 8) | ((ptr[2] | (ptr[1] << 8)) >> 8));
}
