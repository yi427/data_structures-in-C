#include "povector.h"
#include <stdio.h>

int main() {
  const int M = 1e1;
  Vector_t *v = Vector_Construction();
  for (int i = 0; i < M; ++i) {
    Vector_Push_Back(v, i);
  }
  for (int i = 0; i < M; ++i) {
    Vector_Push_Front(v, i);
  }
  Vector_Pop_Front(v);
  for (size_t i = 0; i < Vector_Size(v); ++i) {
    printf("%d ", Vector_Get(v, i));
  }
  printf("\n");
  Vector_Pop_Front(v);
  for (size_t i = 0; i < Vector_Size(v); ++i) {
    printf("%d ", Vector_Get(v, i));
  }
  Vector_Deconstruction(v);
  return 0;
}
