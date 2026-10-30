#ifndef LIBC_H
#define LIBC_H

#include "types.h"

typedef u32 size_t;

/* The system heap; its layout is described by __osMallocInit. */
typedef struct Arena Arena;
extern Arena D_8009D0F0;

void *malloc(size_t size);
void *malloc_r(size_t size);
void *realloc(void *ptr, size_t size);
void *calloc(size_t count, size_t size);
void free(void *ptr);

void bzero(void *s, size_t n);
size_t strlen(const char *s);
char *strchr(const char *s, s32 c);
void *memcpy(void *dst, const void *src, size_t n);
void *memset(void *s, s32 c, size_t n);

/* Heap routines under the address name of the ROM; they take the heap as first argument. */
void *func_8008743C(Arena *arena, size_t size);
void *func_8008747C(Arena *arena, size_t size);
void *func_8008766C(Arena *arena, void *ptr, size_t size);
void Arena_Free(Arena *arena, void *ptr);
void func_800878AC(Arena *arena, u32 *maxFree, u32 *bytesFree, u32 *bytesAllocated);
s32 func_8008795C(Arena *arena);
void func_8008736C(Arena *arena);
u8 func_8008738C(Arena *arena);
void __osMallocInit(Arena *arena, void *start, size_t size);

void GetFreeArena(u32 *maxFree, u32 *bytesFree, u32 *bytesAllocated);
s32 CheckArena(void);
void MallocInit(void *start, size_t size);
void MallocCleanup(void);
u8 MallocIsInitialized(void);

#endif
