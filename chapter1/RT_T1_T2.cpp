#include <iostream>

template <typename T1, typename T2, typename RT> RT max(T1 a, T2 b) {
  return a > b ? a : b;
}

int main(int argc, char *argv[]) {
  int a = 42;

  std::cout << "max<float, float, int>(44.4, a) = "
            << ::max<float, float, int>(44.4, a) << std::endl;
  std::cout << "max<int, float, int>(42.9999, a) = "
            << ::max<int, float, int>(42.9999, a) << std::endl;
  std::cout << "max<float, float, float>(42.9999, a) = "
            << ::max<float, float, float>(42.9999, a) << std::endl;
  std::cout << "max<int, float, float>(42.9999, a) = "
            << ::max<int, float, float>(42.9999, a) << std::endl;
  std::cout << "max<int, float, char>(42.9999, a) = "
            << ::max<int, float, char>(42.9999, a) << std::endl;

  return 0;
}
