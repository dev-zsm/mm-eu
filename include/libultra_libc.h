#ifndef LIBULTRA_LIBC_H
#define LIBULTRA_LIBC_H

#include "ultra64.h"
#include "os_pfs.h"
#include "os_sp.h"
#include "os_vi.h"

/* 64-bit integer support the compiler calls for operations the 32-bit target has no instruction for. */
u64 __ull_rshift(u64 x, u64 shift);
u64 __ull_rem(u64 x, u64 y);
u64 __ull_div(u64 x, u64 y);
u64 __ll_lshift(u64 x, u64 shift);
u64 __ll_rem(u64 x, u64 y);
s64 __ll_div(s64 x, s64 y);
s64 __ll_mul(s64 x, s64 y);
void __ull_divremi(u64 *quot, u64 *rem, u64 x, volatile u16 y);
s64 __d_to_ll(f64 x);
s64 __f_to_ll(f32 x);
u64 __d_to_ull(f64 x);
u64 __f_to_ull(f32 x);
f64 __ll_to_d(s64 x);
f32 __ll_to_f(s64 x);
f64 __ull_to_d(u64 x);
f32 __ull_to_f(u64 x);

typedef struct {
    /* 0x0 */ s32 quot;
    /* 0x4 */ s32 rem;
} ldiv_t;

typedef struct {
    /* 0x00 */ s64 quot;
    /* 0x08 */ s64 rem;
} lldiv_t;

ldiv_t ldiv(s32 num, s32 den);
lldiv_t lldiv(s64 num, s64 den);

/* Sleep for a time given in CPU cycles, nanoseconds, microseconds, milliseconds or seconds. */
#define OS_CPU_COUNTER 46875000

void csleep(OSTime cycles);
void nsleep(u32 ns);
void usleep(u32 us);
void msleep(u32 ms);
void sleep(u32 s);

extern char D_80099340[]; /* "Reset" */

void Reset(void);
#define OS_MESG_TYPE_VRETRACE 13
#define OS_MESG_TYPE_COUNTER 14

extern u32 D_8009E98C; /* incremented at every retrace */

OSViContext *__osViGetCurrentContext(void);
void viMgrMain(void *args);

extern OSTask D_8009D140; /* physical-address copy of the task given to _VirtualToPhysicalTask */

/* Cache of the inode page and of the banks that hold the pages of a file. */
typedef struct {
    /* 0x000 */ __OSInode inode;
    /* 0x100 */ u8 bank;
    /* 0x101 */ u8 map[256];
} __OSInodeCache;

s32 corrupted(OSPfs *pfs, __OSInodeUnit fpage, __OSInodeCache *cache);

/* Copies n bytes with the right direction when the ranges overlap. */
void *func_80096AD0(void *dst, const void *src, u32 n);

#endif
