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
typedef struct 
{
  void *unk0;
  s32 unk4;
  u16 unk8;
  u16 unkA;
  u16 unkC;
  u8 unkE;
  u8 unkF;
  s32 unk10;
} Obj;
s32 GfxPrint_Callback(s32 arg0, u8 *arg1, s32 arg2);
void GfxPrint_Init(Obj *arg0)
{
  arg0->unkF &= ~0x80;
  arg0->unk0 = (void *) GfxPrint_Callback;
  arg0->unkF &= ~1;
  arg0->unkF &= ~2;
  arg0->unkF |= 4;
  arg0->unk4 = ((((((((0 & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF;
  arg0->unk8 = 0;
 if (0) { }
  arg0->unkA = 0;
  arg0->unkC = 0;
  arg0->unkE = 0;
  arg0->unk10 = 0;
  arg0->unkF |= 8;
}
