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
unsigned char AudioThread_QueueCmdS32(M2C_UNK, s32);
M2C_UNK Audio_ResetForAudioHeapStep3();
extern u8 D_801D3E04;
extern M2C_UNK D_801D4260;
void func_801A5C68(void)
{
  int new_var2;
  int new_var;
 if (1 != 0) { } new_var2 = D_801D3E04 * 4; Audio_ResetForAudioHeapStep3();
  new_var2 = (s32) D_801D3E04;
  if (new_var2 < 0xA)
  {
    new_var = new_var2;
    AudioThread_QueueCmdS32(0xE6000100, (*((&D_801D4260) + new_var)) + 0x18);
  }
}
