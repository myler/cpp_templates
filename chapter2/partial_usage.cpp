#include <cassert>
#include <iostream>
#include <string>
#include <vector>

namespace CHECK {
class Unprintable {};
template <typename T1, typename T2>
Unprintable operator==(const T1 &, const T2 &);

template <typename T1, typename T2 = T1> class Equal {
public:
  enum {
    implemented =
        !std::is_same<decltype(std::declval<T1>() == std::declval<T2>()),
                      Unprintable>::value
  };
};
} // namespace CHECK

template <typename T> class Stack {
private:
  std::vector<T> elems;

public:
  Stack(){};
  void push(const T &elem);
  T pop();
  const T &top() const;
  bool empty() const;
  size_t size() const;
  template <typename T2>
  friend std::ostream &operator<<(std::ostream &os, const Stack<T2> &s);
};

template <typename T> void Stack<T>::push(const T &elem) {
  elems.push_back(elem);
}

template <typename T> T Stack<T>::pop() {
  assert(!elems.empty());
  T top = elems.back();
  elems.pop_back();
  return top;
}

template <typename T> const T &Stack<T>::top() const {
  assert(!elems.empty());
  return elems.back();
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Stack<T> &s) {
  // TODO: How to check a T type class has operator<< implementation
  if(CHECK::Equal<T>::implemented) {
    os << s.top();
    // std::cerr << "T type is " << typeid(T).name() << std::endl;
    return os;
  }

  return os << "operator<< is not supported for " << typeid(T).name();
}

template <typename T> bool Stack<T>::empty() const { return elems.empty(); }

template <typename T> size_t Stack<T>::size() const { return elems.size(); }

int main(int argc, char *argv[]) {
  Stack<int> istack;
  Stack<std::string> sstack;

  istack.push(42);
  istack.push(44.4);
  std::cout << "top of istack = " << istack << std::endl;


  Stack<std::pair<int, int>> pstack;
  pstack.push({41, 42});
  std::cout << "top of pstack = " << pstack << std::endl;

  return 0;
}
