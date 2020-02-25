#include <iostream>

int max(int a, int b) { return a > b ? a : b; }

template <typename T> T max(T a, T b) { return a > b ? a : b; }

int main(int argc, char *argv[]) {
  int a = 42;

  std::cout << "max(a, 44) = " << ::max(a, 44) << std::endl;
  std::cout << "max(a, a) = " << ::max(a, a) << std::endl;
  std::cout << "max(44.0, 42.0) = " << ::max(44.0, 42.0) << std::endl;
  std::cout << "max('a', 'b') = " << ::max('a', 'b') << std::endl;
  std::cout << "max<>(44, a) = " << ::max<>(44, a) << std::endl;

  return 0;
}
