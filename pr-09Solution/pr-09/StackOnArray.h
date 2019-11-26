#pragma once
#include <assert.h>
#include <cmath>
#include <iostream>
using namespace std;

template <typename TElement>
class stackInArray {
 private:
  unsigned int sizeOfStack;
  unsigned int capacity;
  TElement* array;

 public:
  stackInArray(const unsigned int maxSize) {
    sizeOfStack = 0;
    capacity = maxSize;
    array = new TElement[maxSize];
  }
  stackInArray(const stackInArray& stack) {
    sizeOfStack = stack.sizeOfStack;
    capacity = stack.capacity;
    array = new TElement[stack.sizeOfStack];
    for (int i = 0; i < stack.sizeOfStack; i++) {
      array[i] = stack.array[i];
    }
  }
  stackInArray operator=(const stackInArray& stack) {
    sizeOfStack = stack.sizeOfStack;
    capacity = stack.capacity;
    array = new TElement[stack.sizeOfStack];
    for (int i = 0; i < stack.sizeOfStack; i++) {
      array[i] = stack.array[i];
    }
    return *this;
  }
  stackInArray(stackInArray&& stack) {
    sizeOfStack = stack.sizeOfStack;
    capacity = stack.capacity;
    array = new TElement[stack.sizeOfStack];
    for (int i = stack.sizeOfStack - 1; i >= 0; i--) {
      array[i] = stack.array[i];
      stack.array[i] = nullptr;
      stack.pop();
    }
  }
  stackInArray operator=(stackInArray&& stack) {
    sizeOfStack = stack.sizeOfStack;
    capacity = stack.capacity;
    array = new TElement[stack.sizeOfStack];
    for (int i = stack.sizeOfStack - 1; i >= 0; i--) {
      array[i] = stack.array[i];
      stack.array[i] = nullptr;
      stack.pop();
    }
    return *this;
  }
  bool operator==(stackInArray stack) {
    if (this->size() == stack.size()) {
      for (int i = 0; i < stack.size(); i++) {
        if (this->array[i] != stack.array[i]) {
          return false;
        }
      }
      return true;
    }
    return false;
  }
  bool operator!=(stackInArray stack) {
    if (*this == stack) {
      return false;
    }
    return true;
  }
  ~stackInArray() { delete[] array; }
  bool IsEmpty() {
    if (sizeOfStack == 0) {
      return true;
    } else {
      return false;
    }
  }
  void push(const TElement newElement) {
    // assert(sizeOfStack != capacity - 1 && "Your stack is full");
    if (sizeOfStack == capacity - 1) {
      TElement a[100000];
      for (int i = 0; i < capacity; i++) {
        a[i] = this->array[i];
      }
      delete[] array;
      capacity *= 2;
      const int NewMaxSize = capacity;
      array = new TElement[NewMaxSize];
      for (int i = 0; i < capacity / 2; i++) {
        array[i] = a[i];
      }
    }
    array[sizeOfStack] = newElement;
    sizeOfStack++;
  }
  void pop() {
    assert(sizeOfStack != 0 && "The size of your stack = 0");
    sizeOfStack--;
  }
  TElement top() {
    assert(sizeOfStack != 0 && "You stack is empty");
    return array[sizeOfStack - 1];
  }
  unsigned int size() { return sizeOfStack; }
};