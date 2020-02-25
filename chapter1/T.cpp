#include <iostream>

template <typename T> T max(T a, T b) { return a > b ? a : b; }

int main(int argc, char *argv[]) {
  int a = 42;

  std::cout << "max(a, 44) = " << ::max(a, 44) << std::endl;
  std::cout << "max(a, a) = " << ::max(a, a) << std::endl;
  std::cout << "max(44, a) = " << ::max(44, a) << std::endl;
  std::cout << "max(a, -1) = " << ::max(a, -1) << std::endl;
  std::cout << "max(-0, a) = " << ::max(-0, a) << std::endl;
  std::cout << "max<int>(44.4, a) = " << ::max<int>(44.4, a) << std::endl;

  return 0;
}
