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
extern s16 D_801C03DC;
extern M2C_UNK D_801E6EF0;
void func_801129F8(u8 *arg0)
{
  unsigned long long new_var;
  *((s16 *) (((s8 *) (&D_801E6EF0)) + 0x3F38)) = 1;
  *((s16 *) (((s8 *) (&D_801E6EF0)) + 0x3F3A)) = 0;
  *((s16 *) (((s8 *) (&D_801E6EF0)) + 0x3F3C)) = 0;
  D_801C03DC = 0;
  new_var = 0;
  *((s16 *) (((s8 *) arg0) + 0x16C4A)) = 0;
  *((s16 *) (((s8 *) arg0) + 0x16C46)) = new_var;
  *((s16 *) (((s8 *) arg0) + 0x16C44)) = new_var;
  *((s16 *) (((s8 *) arg0) + 0x16C48)) = 0x14;
}
