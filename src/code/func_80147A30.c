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
extern char D_801C81E8;
extern M2C_UNK D_801C81F4;
void func_80147A30(void)
{
  s8 *new_var;
  new_var = (s8 *) (&D_801C81F4);
  D_801C81E8 = 0xFF;
  *((s16 *) (((s8 *) (&D_801C81F4)) + 0x10)) = 0;
  *((s16 *) (new_var + 0xE)) = (s16) (*((s16 *) (((s8 *) (&D_801C81F4)) + 0x10)));
  *((s16 *) (((s8 *) (&D_801C81F4)) + 0xC)) = (s16) (*((s16 *) (((s8 *) (&D_801C81F4)) + 0x10)));
  *((s16 *) (((s8 *) (&D_801C81F4)) + 0xA)) = (s16) (*((s16 *) (new_var + 0x10)));
  *((s16 *) (((s8 *) (&D_801C81F4)) + 8)) = (s16) (*((s16 *) (((s8 *) (&D_801C81F4)) + 0x10)));
  *((s16 *) (((s8 *) (&D_801C81F4)) + 6)) = (s16) (*((s16 *) (((s8 *) (&D_801C81F4)) + 0x10)));
  *((s16 *) (new_var + 4)) = (s16) (*((s16 *) (new_var + 0x10)));
  *((s16 *) (new_var + 2)) = (s16) (*((s16 *) (new_var + 0x10)));
  *((s16 *) (new_var + 0)) = (s16) (*((s16 *) (new_var + 0x10)));
}
