#include <iostream>

template <typename T> T max(T a, T b) {
  std::cout << "max<T>()" << std::endl;
  return a > b ? a : b;
}

template <typename T> T max(T a, T b, T c) { return max(max(a, b), c); }

int max(int a, int b) {
  std::cout << "max(int, int)" << std::endl;
  return a > b ? a : b;
}

int main(int argc, char *argv[]) {
  ::max(47, 11, 33);
  return 0;
}
