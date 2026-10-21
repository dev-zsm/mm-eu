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
typedef struct Obj
{
  u8 pad0[0x278];
  u64 unk278;
} Obj;
extern volatile long long D_80096D10[1];
extern s32 D_80096D18[1];
extern u64 func_800905C0(void);
extern void func_800813B8(Obj *a, Obj *b);
void func_8008161C(Obj *arg0)
{
  u64 t;
  if (D_80096D10[0] == 0)
  {
    if (arg0->unk278 == 0)
    {
      arg0->unk278 = func_800905C0();
    }
    else
    {
      t = func_800905C0();
      D_80096D10[0] = t - arg0->unk278;
    }
  }
  D_80096D18[0] += 1;
  func_800813B8(arg0, arg0);
}
