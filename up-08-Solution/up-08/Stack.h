#pragma once
#include "Containers.h"
template <typename T>
class Stack {
 public:
  Stack();
  void Push(const T& data);
  T Pop();
  const T& Get();
  unsigned int Size();
  bool IsEmpty();
 private:
  BiDirectionalList<T> list;
};
template <typename T>
Stack<T>::Stack() {}
template <typename T>
void Stack<T>::Push(const T& data) {
  list.PushBack(data);
}
template <typename T>
T Stack<T>::Pop() {
  return list.PopBack();
}
template <typename T>
const T& Stack<T>::Get() {
  return list.Back();
}
template <typename T>
unsigned int Stack<T>::Size() {
  return list.Size();
}
template <typename T>
bool Stack<T>::IsEmpty() {
  return list.IsEmpty();
}