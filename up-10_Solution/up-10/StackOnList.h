#ifndef STACK_H
#define STACK_H
#pragma once
#include <algorithm>
#include <cassert>
#include <cmath>
#include <initializer_list>
#include <memory>
#include <vector>

using namespace std;

template <class T>
class StackOnList {
 private:
  class Node {
   private:
    T value_;
    unique_ptr<Node> last_;

   public:
    Node() : value_(0), last_(nullptr){};
    Node(T value) : value_(value), last_(nullptr){};
    Node(T value, Node* last) : value_(value), last_(last){};
    ~Node(){};
    unique_ptr<Node> GetLast() { return move(last_); };
    T GetValue() const { return value_; };
    void SetLast(const Node* last) { last_ = last; };
    void SetValue(T value) { value_ = value; };
  };
  unique_ptr<Node> Top_;
  size_t Size_;

 public:
  StackOnList();
  StackOnList(initializer_list<T> list);
  ~StackOnList();
  size_t Size() const { return Size_; };
  bool IsEmpty() const { return !Size_; }
  T Top() const {
    if (!Size_) return nullptr;
    return Top_->GetValue();
  }
  const Node const* ConstTop() const {
    if (!Size_) return nullptr;
    return Top_;
  }
  void Push(const T& value) {
    Size_++;
    Top_ = unique_ptr<Node>(new Node(value, Top_.get()));
  }
  T Pop() {
    assert(Size_ != 0);
    Size_--;
    T value = Top_->GetValue();
    Top_ = move(Top_->GetLast());
    return value;
  }
  bool operator==(const StackOnList& Second) const;
  bool operator!=(const StackOnList& Second) const;
  StackOnList(const StackOnList& Second);
  StackOnList(StackOnList&& Second);
  StackOnList& operator=(const StackOnList& Second);
  StackOnList& operator=(StackOnList&& Second);
};
template <class T>
StackOnList<T>::StackOnList() : Top_(nullptr), Size_(0){};
template <class T>
StackOnList<T>::StackOnList(initializer_list<T> list) {
  Size_ = 0;
  Top_.release();
  for (auto new_val : list) {
    Size_++;
    Top_ = unique_ptr<Node>(new Node(new_val, Top_.get()));
  }
};
template <class T>
StackOnList<T>::~StackOnList(){};
template <class T>
bool StackOnList<T>::operator==(const StackOnList<T>& Second) const {
  if (Size_ != Second.Size()) return false;
  unique_ptr<Node> This = move(Top_);
  unique_ptr<Node> NoThis = move(Second.Top());
  while (This != nullptr) {
    if (This.GetValue() != NoThis.GetValue()) return false;
    This = move(This.GetLast());
    NoThis = move(NoThis.GetLast());
  }
  return true;
}
template <class T>
bool StackOnList<T>::operator!=(const StackOnList<T>& Second) const {
  return !(*this == Second);
}
template <class T>
StackOnList<T>::StackOnList(const StackOnList<T>& Second) {
  vector<T> NS;
  Top_.release();
  Size_ = Second.Size();
  Node* NoThis = Second.Top_;
  while (NoThis != nullptr) {
    NS.push_back(NoThis.GetValue());
    NoThis = move(NoThis.Top_.GetLast());
  }
  for (int i = NS.size() - 1; i >= 0; i--) {
    Top_ = unique_ptr<Node>(new Node(NS[i], Top_));
  }
}
template <class T>
StackOnList<T>::StackOnList(StackOnList<T>&& Second) {
  Top_.release();
  Size_ = Second.Size();
  Top_ = move(Second.Top_);
  Second.Top_.release();
}
template <class T>
StackOnList<T>& StackOnList<T>::operator=(const StackOnList<T>& Second) {
  if (this == &Second) return *this;

  std::vector<T> NS;
  Top_.release();
  Size_ = Second.Size();
  unique_ptr<Node> NoThis = move(Second.Top_);
  while (NoThis != nullptr) {
    NS.push_back(NoThis.GetValue());
    NoThis = NoThis.Top_.GetLast();
  }
  for (int i = NS.size() - 1; i >= 0; i--) {
    Top_ = new Node(NS[i], Top_);
  }
  return *this;
}
template <class T>
StackOnList<T>& StackOnList<T>::operator=(StackOnList<T>&& Second) {
  if (this == &Second) {
    return *this;
  }
  Top_.release();
  Size_ = Second.Size();
  Top_ = move(Second.Top_);
  Second.Top_ = nullptr;
  return *this;
}

#endif  // !STACK.H