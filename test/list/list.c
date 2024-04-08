#include <stdlib.h>
#include "polist.h"

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


void List_Display(const list_t *t) {
  printf("digraph G {\n");
  printf("rankdir=LR;\n");
  int i = 0;
  node_t *curr = List_Begin(t);
  while (curr) {
    printf("node%d[label=\"%d\"];\n", i, *(int *)curr->val);
    curr = Node_Next(curr);
    i++;
  }
  i = 0; curr = List_Begin(t);
  while (curr) {
    if (Node_Prev(curr) == NULL) {
      printf("node%d -> headNull;\n", i);
    } else {
      printf("node%d -> node%d;\n", i, i-1);
    }
    if (Node_Next(curr) == NULL) {
      printf("node%d -> tailNull;\n", i);
    } else {
      printf("node%d -> node%d;\n", i, i+1);
    }
    curr = Node_Next(curr);
    i++;
  }
  printf("\n}");
}

int main() {
  list_t *t = List_Construction();
  List_Init(t,(void *)get);
  for (int i = 0; i < 10; ++i) {
    List_Push_Back(t, (void*)&i);
  }
  for (int i = 0; i < 10; ++i) {
    List_Push_Front(t, (void*)&i);
  }
  List_Display(t);
  List_Clean(t);
  return 0;
}

