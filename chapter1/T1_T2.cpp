#include <iostream>

template <typename T1, typename T2> T1 max(T1 a, T2 b) { return a > b ? a : b; }

int main(int argc, char *argv[]) {
  int a = 42;

  std::cout << "max(a, 44.4) = " << ::max(a, 44.4) << std::endl;
  std::cout << "max(a, a) = " << ::max(a, a) << std::endl;
  std::cout << "max(44.4, a) = " << ::max(44.4, a) << std::endl;
  std::cout << "max(a, -1) = " << ::max(a, -1.0) << std::endl;
  std::cout << "max(-0, a) = " << ::max(-0, a) << std::endl;
  std::cout << "max<int>(44.4, a) = " << ::max<int>(44.4, a) << std::endl;
  std::cout << "max<double>(44.4, a) = " << ::max<double>(44.4, a) << std::endl;
  std::cout << "max<int, double>(44.4, a) = " << ::max<int, double>(44.4, a)
            << std::endl;
  std::cout << "max<int, double>(44, a) = " << ::max<int, double>(44, a)
            << std::endl;
  std::cout << "max<double, double>(a, 44.4) = " << ::max<double, double>(a, 44.4)
            << std::endl;

  return 0;
}
