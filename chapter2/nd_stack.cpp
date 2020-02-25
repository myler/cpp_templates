#include <cassert>
#include <iostream>
#include <string>
#include <vector>

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

template <typename T> bool Stack<T>::empty() const { return elems.empty(); }

template <typename T> size_t Stack<T>::size() const { return elems.size(); }

int main(int argc, char *argv[]) {
  using ND_Stack = Stack<Stack<Stack<int>>>;
  ND_Stack nstack;

  Stack<int> istack;
  istack.push(42);

  Stack<Stack<int>> sstack;
  sstack.push(istack);

  nstack.push(sstack);

  std::cout << "ND Stack top int = " << nstack.top().top().top() << std::endl;

  return 0;
}
