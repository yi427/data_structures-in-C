#include "poschash.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int *get(int *num) {
  int *res = (int *)malloc(sizeof(int));
  *res = *num;
  return res;
}

int
main() {
  list_t *l = (list_t *)malloc(sizeof(list_t));
  List_Init(l, (void *)get);
  for (int i = 0; i < 10; ++i) {
    List_Push_Front(l, &i);
  }
  node_t *curr = l->head;
  int len = 0;
  while (curr != NULL) {
    printf("%d->", *(int *)curr->val);
    len++;
    curr = curr->next;
  }
  printf("NULL\n");
  assert(len == l->len);
  List_Clean(l);
  return 0;
}
