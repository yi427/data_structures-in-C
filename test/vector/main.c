#include <stdio.h>
#include "povector.h"

int 
main() {
  Vector_t * v = Vector_Construction();
  for (int i = 0; i < 10; ++i) {
    Vector_Push_Back(v, i);
  }
  for (size_t i = 0; i < Vector_Size(v); ++i) {
    printf("%d ", Vector_Get(v, i));
  }
  Vector_Deconstruction(v);
  return 0;
}
