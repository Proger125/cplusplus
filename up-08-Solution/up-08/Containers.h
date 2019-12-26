#pragma once
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class BiDirectionalList {
  struct Node {
    T value;

   private:
    Node* next;
    Node* prev;
    Node(T data, Node* nextNode, Node* prevNode) {
      value = data;
      next = nextNode;
      prev = prevNode;
    }
    friend class BiDirectionalList;
  };

 public:
  BiDirectionalList();
  BiDirectionalList(const BiDirectionalList& list);
  BiDirectionalList(BiDirectionalList& list);
  unsigned int Size();
  bool IsEmpty();
  void PushFront(const T& data);
  void PushBack(const T& data);
  Node* Front() { return head; }
  Node* Back() { return tail; }
  T PopFront();
  T PopBack();
  vector<T> ToVector();
  int Find(const T& data);
  vector<int> FindAll(const T& data);
  Node* operator[](int j) {
    int i = 0;
    Node* node = head;
    while (i != j) {
      head = head->next;
      i++;
    }
    Node* res = head;
    head = node;
    return res;
  }
  void InsertBefore(Node* element, const T& data);
  void InsertAfter(Node* element, const T& data);
  void Erase(Node* element);
  bool operator==(BiDirectionalList& list);
  bool operator!=(BiDirectionalList& list);

 private:
  unsigned int size;
  Node* head;
  Node* tail;
};
template <typename T>
BiDirectionalList<T>::BiDirectionalList() {
  size = 0;
  head = tail = NULL;
}
template <typename T>
BiDirectionalList<T>::BiDirectionalList(BiDirectionalList& list) {
  Node* node = list.head;
  while (list.head != list.tail) {
    this->PushBack(list.head->value);
    list.head = list.head->next;
  }
  this->PushBack(list.tail->value);
  list.head = node;
}
// template <typename T>
// BiDirectionalList<T>::BiDirectionalList(BiDirectionalList& list) {
//  while (!list.IsEmpty()) {
//    this->PushBack(list.PopBack());
//  }
//  this->PushBack(list.PopBack());
//}
template <typename T>
unsigned int BiDirectionalList<T>::Size() {
  return size;
}
template <typename T>
bool BiDirectionalList<T>::IsEmpty() {
  if (size == 0) {
    return true;
  } else {
    return false;
  }
}
template <typename T>
void BiDirectionalList<T>::PushFront(const T& data) {
  if (!IsEmpty()) {
    Node* node = new Node(data, head, NULL);
    size++;
    head->prev = node;
    head = node;
  } else {
    Node* node = new Node(data, NULL, NULL);
    size++;
    head = tail = node;
  }
}
template <typename T>
void BiDirectionalList<T>::PushBack(const T& data) {
  if (!IsEmpty()) {
    Node* node = new Node(data, NULL, tail);
    size++;
    tail->next = node;
    tail = node;
  } else {
    Node* node = new Node(data, NULL, NULL);
    size++;
    tail = head = node;
  }
}
template <typename T>
T BiDirectionalList<T>::PopFront() {
  if (!IsEmpty()) {
    T res = head->value;
    Node* node = head;
    head = head->next;
    delete node;
    size--;
    return res;
  } else {
    assert(IsEmpty() && "Your list is empty");
  }
}
template <typename T>
T BiDirectionalList<T>::PopBack() {
  if (!IsEmpty()) {
    T res = tail->value;
    Node* node = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete node;
    size--;
    return res;
  } else {
    assert(IsEmpty() && "Your list is empty");
  }
}
template <typename T>
vector<T> BiDirectionalList<T>::ToVector() {
  vector<T> v;
  Node* node = head;
  while (head != tail) {
    v.push_back(head->value);
    head = head->next;
  }
  head = node;
  v.push_back(tail->value);
  return v;
}
template <typename T>
int BiDirectionalList<T>::Find(const T& data) {
  int i = 0;
  Node* node = head;
  while (head->value != data) {
    i++;
    head = head->next;
  }
  if (head->value == data) {
    head = node;
    return i;
  } else {
    head = node;
    return -1;
  }
}
template <typename T>
vector<int> BiDirectionalList<T>::FindAll(const T& data) {
  int i = 0;
  vector<int> v;
  Node* node = head;
  while (head != tail) {
    if (head->value == data) {
      v.push_back(i);
    }
    i++;
    head = head->next;
  }
  head = node;
  if (tail->value == data) {
    v.push_back(size - 1);
  }
  return v;
}
template <typename T>
void BiDirectionalList<T>::InsertBefore(Node* element, const T& data) {
  Node* node = new Node(data, element, element->prev);
  size++;
  element->prev->next = node;
  element->prev = node;
  element = node;
}
template <typename T>
void BiDirectionalList<T>::InsertAfter(Node* element, const T& data) {
  Node* node = new Node(data, element->next, element);
  size++;
  element->next->prev = node;
  element->next = node;
  element = node;
}
template <typename T>
void BiDirectionalList<T>::Erase(Node* element) {
  if (!IsEmpty()) {
    element->prev->next = element->next;
    element->next->prev = element->prev;
    delete element;
    size--;
  }
}
template <typename T>
bool BiDirectionalList<T>::operator==(BiDirectionalList<T>& list) {
  if (Size() == list.Size()) {
    Node* node1 = head;
    Node* node2 = list.head;
    if (tail->value != list.tail->value) {
      return false;
    } else {
      while (head != tail) {
        if (head->value != list.head->value) {
          return false;
        }
        head = head->next;
        list.head = list.head->next;
      }
      head = node1;
      list.head = node2;
      return true;
    }
  } else {
    return false;
  }
}
template <typename T>
bool BiDirectionalList<T>::operator!=(BiDirectionalList<T>& list) {
  if (*this == list) {
    return false;
  } else {
    return true;
  }
}