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
typedef struct Node
{
  struct Node *next;
  struct Node *prev;
  u32 start;
  u32 end;
  u32 fill;
  s32 limit;
  s32 unk18;
} Node;
extern s32 D_80096DE0;
extern s32 D_80096DE4;
void func_80085390(Node *arg0, u32 arg1, u32 arg2, u32 arg3, s32 arg4, s32 arg5)
{
  char new_var;
  Node *v0;
  Node *tail;
  u32 p;
  if (arg0 == ((void *) 0))
  {
    *((Node **) (&D_80096DE0)) = (void *) 0;
    return;
  }
  arg0->start = arg1;
  arg0->end = arg2;
  arg0->fill = arg3;
  arg0->limit = arg4;
  arg0->unk18 = arg5;
  v0 = *((Node **) (&D_80096DE0));
  if (v0 != ((void *) 0))
  {
    do
    {
      if (v0 == arg0)
      {
        return;
      }
      v0 = v0->next;
    }
    while (v0 != ((void *) 0));
  }
  arg0->prev = *((Node **) (&D_80096DE4));
  arg0->next = (void *) 0;
  new_var = 0;
  if ((*((Node **) (&D_80096DE4))) != ((void *) new_var))
  {
    (*((Node **) (&D_80096DE4)))->next = arg0;
  }
  *((Node **) (&D_80096DE4)) = arg0;
  if ((*((Node **) (&D_80096DE0))) == ((void *) new_var))
  {
    *((Node **) (&D_80096DE0)) = arg0;
  }
  if (arg0->limit != (-1))
  {
    p = arg0->start;
    if (p < arg0->end)
    {
      do
      {
        p += 4;
        *((u32 *) (p - 4)) = arg0->fill;
      }
      while (p < arg0->end);
    }
  }
}
