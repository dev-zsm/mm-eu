// FLAGS: -O2 -g0 -mips2

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
extern u8 D_800980F4;
extern u8 D_8009E9A0[];
s32 func_8008B630(s32 a0, s32 a1);
s32 func_8008AF10(s32 a0, void *a1);
s32 func_80088070(void *a0, void *a1, s32 a2);
s32 func_8008B6F4(s32 a0, void *a1);
s32 func_8008B560(void *a0, s32 a1)
{
  s32 sp2C;
  u8 sp28[4];
  u8 sp24[4];
  s32 v;
  D_800980F4 = 0xFA;
  func_8008B630(a1, 0);
  func_8008AF10(1, D_8009E9A0);
  func_80088070(a0, sp28, 1);
  sp2C = func_8008AF10(0, D_8009E9A0);
  func_80088070(a0, sp28, 1);
  func_8008B6F4(a1, sp24);
  v = sp24[2];
 do { } while (0);
  if ((v & 1) && (v & 2))
  {
    return 2;
  }
  if ((sp24[3] != 0) || (!(v & 1)))
  {
    return 1;
  }
  if (v & 4)
  {
    return 4;
  }
  return sp2C;
}
