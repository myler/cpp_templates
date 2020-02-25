#include <iostream>
#include <type_traits>

template <typename T1, typename T2,
          typename RT = std::decay_t<decltype(true ? T1() : T2())>>
RT max(T1 a, T2 b) {
  return a > b ? a : b;
}

int main(int argc, char *argv[]) {
  int a = 42;

  std::cout << "max(44.4, a) = " << ::max(44.4, a) << std::endl;
  std::cout << "max<int, float>(42.9999, a) = " << ::max<int, float>(42.9999, a)
            << std::endl;
  std::cout << "max<float, float, float>(42.9999, a) = "
            << ::max<float, float>(42.9999, a) << std::endl;
  std::cout << "max<int, float>(42.9999, a) = " << ::max<int, float>(42.9999, a)
            << std::endl;
  std::cout << "max<int, float, char>(42.9999, a) = "
            << ::max<int, float, char>(42.9999, a) << std::endl;

  return 0;
}
