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
  s16 type;
  s16 flag;
  u32 val;
  struct Node *next;
} Node;
extern void ArenaImpl_Lock(void);
extern void ArenaImpl_Unlock(void);
s32 func_8008795C(Node **head)
{
  Node *node;
  s32 ret;
 if (0) { }
  ret = 0;
  if ((((!head) && (!head)) && (!head)) != 0)
  {
  }
  ArenaImpl_Lock();
  node = *head;
  if (!node)
  {
  }
  if (node != ((void *) 0))
  {
    do
    {
      if (node->type != 0x7373)
      {
        ret = 1;
        break;
      }
      node = node->next;
    }
    while (node != ((void *) ((0, 0))));
  }
  ArenaImpl_Unlock();
  return ret;
}
