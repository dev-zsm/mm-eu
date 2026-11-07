typedef struct A { char pad[0x144]; void (*fn)(struct A *, int); } A;
void func_80A0448C();
void DmHina_Update(A *a, int b) { a->fn(a, b); func_80A0448C(a, b); }
