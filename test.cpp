#include <iostream>

int
main(void) {
  int a[] = {2, 1, 3};
  std::cout << a[1] << '\n';
  std::cout << 1[a] << '\n';
  printf("%p\n", a + 1);
  printf("%p\n", 1 + a);
}
