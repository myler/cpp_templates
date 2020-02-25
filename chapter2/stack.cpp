#include <cassert>
#include <iostream>
#include <vector>

template <typename T> class Stack {
private:
  std::vector<T> elems;

public:
  Stack(){};
  void push(const T &elem);
  void pop();
  const T &top() const;
  bool empty() const;
  size_t size() const;
};

template <typename T> void Stack<T>::push(const T &elem) {
  elems.push_back(elem);
}

template <typename T> void Stack<T>::pop() {
  assert(!elems.empty());
  elems.pop_back();
}

template <typename T> const T &Stack<T>::top() const {
  assert(!elems.empty());
  return elems.back();
}

template <typename T> bool Stack<T>::empty() const { return elems.empty(); }

template <typename T> size_t Stack<T>::size() const { return elems.size(); }

int main(int argc, char *argv[]) {
  Stack<int> s;

  std::cout << "is empty? " << s.empty() << std::endl;

  s.push(1);
  s.push(2);
  s.push(3);

  std::cout << "after 3 push(), stack size = " << s.size() << std::endl;

  std::cout << "is empty? " << s.empty() << std::endl;
  std::cout << "stack top elem = " << s.top() << std::endl;
  s.pop();
  s.pop();
  s.pop();
  std::cout << "after 3 pop(), is empty? " << s.empty() << std::endl;

  return 0;
}
