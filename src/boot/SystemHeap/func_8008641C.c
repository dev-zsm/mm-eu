// FLAGS: -O2 -g0

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
void SystemHeap_RunBlockFunc1(u32 a0, s32 a1, s32 a2, void (*a3)(u32, s32))
{
  u32 end;
  u32 p = a0;
  end = a0;
  end += a1 * a2;
  if (p < end)
  {
    do
    {
      a3(p, 2);
      p += a2 ^ 0;
    }
    while (p < end);
  }
}
