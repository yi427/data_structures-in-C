#include <stdlib.h>
#include "polist.h"

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
  list_t *t = List_Construction();
  List_Init(t,(void *)get);
  for (int i = 0; i < 10; ++i) {
    List_Push_Back(t, (void*)&i);
  }
  for (int i = 0; i < 10; ++i) {
    List_Push_Front(t, (void*)&i);
  }
  size_t len = List_Size(t);
  printf("%d\n", (int)List_Size(t));
  List_Print(t, (print_t)print);
  for (size_t i = 0; i < len; ++i) {
    printf("%ld:", i);
    List_Pop_Back(t);
    // List_Pop_Front(t);
    List_Print(t, (print_t)print);
    printf("\n");
  }
  for (int i = 0; i < 5; ++i) {
    int index = i == 0 ? 0 : i-1;
    List_Insert(t, index, (void*)&i);
    List_Print(t, (print_t)print);
  }
  for (int i = 0; i < 5; ++i) {
    int index = i == 0 ? 0 : i-1;
    printf("%d:", index);
    List_Erase(t, index);
    List_Print(t, (print_t)print);
  }
  List_Clean(t);
  return 0;
}

