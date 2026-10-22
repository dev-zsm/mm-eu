// FLAGS: -O2 -g3 -mips2

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
typedef s32 M2C_UNK;
extern s32 D_801E7DB0;
s16 func_8012F5DC(s16 arg0)
{
  if (arg0 == 0x27)
  {
    return (s16) (((u32) (D_801E7DB0 & 0xFFFF0000)) >> 0x10);
  }
  return (s16) (D_801E7DB0 ^ 0);
}
