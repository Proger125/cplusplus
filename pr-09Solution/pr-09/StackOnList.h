#pragma once
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

template <typename TElement>
struct TNode {
  TElement data;
  TNode<TElement> *next;
  TNode(TElement newData, TNode<TElement> *nextNode) {
    data = newData;
    next = nextNode;
  }
};
template <typename TElement>
class stackInList {
 private:
  unsigned int sizeOfStack;
  TNode<TElement> *currentTop;

 public:
  stackInList() {
    sizeOfStack = 0;
    currentTop = NULL;
  }
  stackInList(const stackInList &stack) {
    currentTop = NULL;
    TNode<TElement> *top = stack.currentTop;
    TElement a[100000];
    int i = 0;
    while (stack.currentTop != nullptr) {
      a[i] = stack.currentTop->data;
      i++;
      stack.currentTop = stack.currentTop->next;
    }
    for (int j = i - 1; j >= 0; j--) {
      TNode<TElement> *node = new TNode<TElement>(a[j], currentTop);
      sizeOfStack++;
      currentTop = node;
    }
    stack.currentTop = top;
  }
  stackInList(stackInList &stack) {
    TElement a[100000];
    int i = 0;
    while (!stack.IsEmpty()) {
      a[i] = stack.pop();
      i++;
    }
    for (int j = i - 1; j >= 0; j--) {
      this->push(a[i]);
    }
  }
  stackInList operator=(const stackInList &stack) {
    currentTop = NULL;
    TNode<TElement> *top = stack.currentTop;
    TElement a[100000];
    int i = 0;
    while (stack.currentTop != nullptr) {
      a[i] = stack.currentTop->data;
      i++;
      stack.currentTop = stack.currentTop->next;
    }
    for (int j = i - 1; j >= 0; j--) {
      TNode<TElement> *node = new TNode<TElement>(a[j], currentTop);
      sizeOfStack++;
      currentTop = node;
    }
    stack.currentTop = top;
    return *this;
  }
  stackInList operator=(stackInList &stack) {
    TElement a[100000];
    int i = 0;
    while (!stack.IsEmpty()) {
      a[i] = stack.pop();
      i++;
    }
    for (int j = i - 1; j >= 0; j--) {
      this->push(a[i]);
    }
    return *this;
  }
  ~stackInList() {
    while (size()) pop();
  }

  void push(const TElement element) {
    TNode<TElement> *node = new TNode<TElement>(element, currentTop);
    sizeOfStack++;
    currentTop = node;
  }
  TElement pop() {
    sizeOfStack--;
    TElement value = currentTop->data;
    TNode<TElement> *node = currentTop;
    currentTop = currentTop->next;
    delete node;
    return value;
  }
  bool IsEmpty() {
    if (sizeOfStack == 0) {
      return true;
    }
    return false;
  }
  TElement top() { return currentTop->data; }
  unsigned int size() { return sizeOfStack; }
  bool operator==(stackInList &stack) {
    if (this->size() == stack.size()) {
      TNode<TElement> *top_this = this->currentTop;
      TNode<TElement> *top_stack = stack.currentTop;
      while (this->currentTop != nullptr) {
        if (this->currentTop->data != stack.currentTop->data) {
          this->currentTop = top_this;
          stack.currentTop = top_stack;
          return false;
        }
        if (this->currentTop->next == nullptr) {
          this->currentTop = top_this;
          stack.currentTop = top_stack;
          return true;
        } else {
          this->currentTop = this->currentTop->next;
          stack.currentTop = stack.currentTop->next;
        }
      }
    } else {
      return false;
    }
  }
  bool operator!=(stackInList &stack) {
    if (*this == stack) {
      return false;
    }
    return true;
  }
};
