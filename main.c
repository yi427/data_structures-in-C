#include <stdlib.h>
#include "include/polist.h"

void print(int *i) {
  printf("%d->", *i);
}

int compare(int *a, int *b) {
  if (*a < *b) return -1;
  else if (*a > * b) return 1;
  return 0;
}

int *get(int *a) {
  int *res = (int*) malloc(sizeof(int));
  *res = *a;
  return res;
}

int main() {
    list_t *t = (list_t*)malloc(sizeof(list_t));
    List_Init(t,(void *)get);
		for (int i = 0; i < 10; ++i) {
			List_Push_Back(t, (void*)&i);
		}
		for (int i = 0; i < 10; ++i) {
			List_Push_Front(t, (void*)&i);
		}
    int i = 2;
    node_t *res = List_Search(t, (compare_t)compare, (void *)&i);
    printf("%d\n", *(int *)res->val);
    List_Print(t, (print_t)print);
    List_Clean(t);
    return 0;
}

