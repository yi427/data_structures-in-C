#include <stdlib.h>
#include "include/polist.h"

void print(int *i) {
  printf("%d\n", *i);
}

int compare(int *a, int *b) {
  if (*a < *b) return -1;
  else if (*a > * b) return 1;
  return 0;
}

int main() {
    list_t *t = (list_t*)malloc(sizeof(list_t));
    List_Init(t);
		for (int i = 0; i < 10; ++i) {
			int *tmp = (int *)malloc(sizeof(int));
			*tmp = i;
			List_Push_Back(t, (void *)tmp);
		}
		for (int i = 0; i < 10; ++i) {
			int *tmp = (int*)malloc(sizeof(int));
			*tmp = i;
			List_Push_Front(t, (void*)tmp);
		}
    int *val = (int*)malloc(sizeof(int));
    *val = 2;
    node_t *res = List_Search(t, (compare_t)compare, val);
    print((int *)res->val);
    // List_Print(t, (print_t)print);
    List_Clean(t);
    return 0;
}

