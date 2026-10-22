// FLAGS: -O1 -g0 -mips3 -32

typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
void __ull_divremi(u64 *q, u64 *r, u64 x, volatile unsigned short y)
{
  *q = x / y;
  *r = x % y;
}
