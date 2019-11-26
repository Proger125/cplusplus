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
bool operator==(stackInList stack) {
    if (stack.size() == this->size()) {
      vector<TElement> v1;
      vector<TElement> v2;
      int k = 0;
      while (stack.size() != 0) {
        TElement a = stack.top();
        TElement b = this->top();
        if (stack.pop() != this->pop()) {
          k = 1;
          v1.push_back(a);
          v2.push_back(b);
          break;
        }
        v1.push_back(a);
        v2.push_back(b);
      }

        if (k == 1) {
        return false;
        } else {
          return true;
		}
    } else {
      return false;
    }
  }
};