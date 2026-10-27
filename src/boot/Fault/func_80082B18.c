// FLAGS: -O2 -g0 -mips2 -trapuv

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
typedef struct Node
{
  u8 pad0[4];
  s32 unk4;
  u8 pad8[4];
  struct Node *unkC;
  u8 pad10[2];
  u16 unk12;
} Node;
extern Node *__osGetActiveQueue(void);
void *Fault_FindFaultedThread(void)
{
  s32 v0;
  Node *tmp;
  s32 *new_var;
 if (0) { }
  tmp = __osGetActiveQueue();
  tmp = tmp;
  if (tmp->unk4 != (-1))
  {
    ;
    do
    {
      if (((tmp->unk4 > 0) && (tmp->unk4 < 0x7F)) && ((tmp->unk12 & 3) != 0))
      {
        return tmp;
      }
      tmp = tmp->unkC;
      new_var = &tmp->unk4;
      v0 = *new_var;
    }
    while (tmp->unk4 != (-1));
  }
  return (void *) 0;
}
