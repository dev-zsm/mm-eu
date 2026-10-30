#ifndef YAZ0_H
#define YAZ0_H

#include "dmamgr.h"
#include "libultra_libc.h"
#include "printf.h"

#define YAZ0_BUFFER_SIZE 0x400

extern u8 *D_8009BDE0;                    /* end of the last output */
extern u8 D_8009BDE8[YAZ0_BUFFER_SIZE];  /* staging buffer for the compressed data */
extern u8 *D_8009C1E8;                    /* end of the buffer while a decompression runs, else NULL */
extern u32 D_8009C1EC;                    /* ROM address of the next block to stage */
extern u32 D_8009C1F0;                    /* compressed bytes still in ROM */
extern u8 *D_8009C1F4;                    /* refill threshold: the read pointer must stay below it */

u8 *Yaz0_FirstDMA(void);
u8 *Yaz0_NextDMA(u8 *src);
s32 Yaz0_DecompressImpl(u8 *src, u8 *dst);
void Yaz0_Decompress(u32 romStart, void *dst, u32 size);

#endif
