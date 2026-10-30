#ifndef OS_SP_H
#define OS_SP_H

#include "ultra64.h"

#define SP_MEM_ADDR_REG 0xA4040000
#define SP_DRAM_ADDR_REG 0xA4040004
#define SP_RD_LEN_REG 0xA4040008
#define SP_WR_LEN_REG 0xA404000C
#define SP_STATUS_REG 0xA4040010
#define SP_PC_REG 0xA4080000

#define SP_IMEM_START 0x04001000

/* SP_STATUS_REG, read side. */
#define SP_STATUS_HALT 0x001
#define SP_STATUS_DMA_BUSY 0x004
#define SP_STATUS_DMA_FULL 0x008
#define SP_STATUS_IO_FULL 0x010
#define SP_STATUS_SIG0 0x080
#define SP_STATUS_SIG1 0x100

/* SP_STATUS_REG, write side. */
#define SPSTATUS_CLEAR_HALT 0x0001
#define SPSTATUS_CLEAR_BROKE 0x0004
#define SPSTATUS_CLEAR_SSTEP 0x0020
#define SPSTATUS_SET_INTR_BREAK 0x0100
#define SPSTATUS_CLEAR_SIG0 0x0200
#define SPSTATUS_SET_SIG0 0x0400
#define SPSTATUS_CLEAR_SIG1 0x0800
#define SPSTATUS_CLEAR_SIG2 0x2000

#define DPC_STATUS_REG 0xA410000C

#define AI_LEN_REG 0xA4500004
#define AI_DACRATE_REG 0xA4500010
#define AI_BITRATE_REG 0xA4500014

#define SI_DRAM_ADDR_REG 0xA4800000
#define SI_PIF_ADDR_RD64B_REG 0xA4800004
#define SI_PIF_ADDR_WR64B_REG 0xA4800010
#define SI_STATUS_REG 0xA4800018

#define SI_STATUS_DMA_BUSY 0x01
#define SI_STATUS_IO_BUSY 0x02

/* OSTask_t.flags */
#define OS_TASK_YIELDED 0x01
#define OS_TASK_DP_WAIT 0x02
#define OS_TASK_YIELD_DATA 0x04

typedef struct {
    /* 0x00 */ u32 type;
    /* 0x04 */ u32 flags;
    /* 0x08 */ u64 *ucode_boot;
    /* 0x0C */ u32 ucode_boot_size;
    /* 0x10 */ u64 *ucode;
    /* 0x14 */ u32 ucode_size;
    /* 0x18 */ u64 *ucode_data;
    /* 0x1C */ u32 ucode_data_size;
    /* 0x20 */ u64 *dram_stack;
    /* 0x24 */ u32 dram_stack_size;
    /* 0x28 */ u64 *output_buff;
    /* 0x2C */ u64 *output_buff_size;
    /* 0x30 */ u64 *data_ptr;
    /* 0x34 */ u32 data_size;
    /* 0x38 */ u64 *yield_data_ptr;
    /* 0x3C */ u32 yield_data_size;
} OSTask_t;

typedef union {
    OSTask_t t;
    u64 force_structure_alignment;
} OSTask;

extern u8 D_8009D280[]; /* message buffer of the Si access queue */
extern OSMesgQueue D_8009D288; /* Si access queue */
extern s32 D_80098020; /* the Si access queue exists */
extern u8 D_8009E7C0[]; /* message buffer of the Pi access queue */
extern OSMesgQueue D_8009E7C8; /* Pi access queue */

OSTask *_VirtualToPhysicalTask(OSTask *task);
void func_8008A780(void *addr, u32 size); /* writeback of the data cache range */
void osInvalDCache(void *addr, u32 size);

void osSpTaskLoad(OSTask *task);
void osSpTaskStartGo(OSTask *task);
void osSpTaskYield(void);
s32 osSpTaskYielded(OSTask *task);

s32 __osSpRawStartDma(s32 direction, u32 devAddr, void *dramAddr, u32 size);
s32 __osSpDeviceBusy(void);
u32 __osSpGetStatus(void);
void __osSpSetStatus(u32 status);
s32 __osSpSetPc(u32 pc);

void __osSiCreateAccessQueue(void);
void __osSiGetAccess(void);
void __osSiRelAccess(void);
s32 __osSiRawStartDma(s32 direction, void *dramAddr);
s32 __osSiRawReadIo(u32 devAddr, u32 *data);
s32 __osSiRawWriteIo(u32 devAddr, u32 data);
s32 __osSiDeviceBusy(void);

u32 osDpGetStatus(void);
void osDpSetStatus(u32 status);

#endif
