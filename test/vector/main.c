#include "povector.h"

int main() {
  const int M = 1e6;
  Vector_t *v = Vector_Construction();
  for (int i = 0; i < M; ++i) {
    Vector_Push_Back(v, i);
  }
  Vector_Deconstruction(v);
  return 0;
}
