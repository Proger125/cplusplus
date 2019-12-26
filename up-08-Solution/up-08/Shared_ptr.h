#pragma once
#ifndef SHARED_PTR_H_
#include <cassert>
template <typename T>
class SharedPtr {
 private:
  T* ptr_;
  size_t* count_;

 public:
  SharedPtr() : ptr_(new T()), count_(new size_t(0)) {}
  SharedPtr(T* ptr) : ptr_(ptr), count_(new size_t(1)){};
  SharedPtr(const SharedPtr<T>& other) {
    ptr_ = other.ptr_;
    count_ = other.count_;
    (*count_)++;
  };
  bool operator==(SharedPtr<T>& other) const { return ptr_ == other.ptr_; }
  bool operator!=(SharedPtr<T>& other) const { return ptr_ != other.ptr_; }
  SharedPtr<T> operator=(SharedPtr<T>& other) {
    if (*this == other) return *this;
    if (count_) {
      if (*count_ == 1) {
        delete ptr_;
        delete count_;
      } else {
        (*count_)--;
      }
    }
    ptr_ = other.ptr_;
    count_ = other.count_;
    (*count_)++;
    return *this;
  }
  ~SharedPtr() {
    if (count_) {
      if (*count_ == 1) {
        delete ptr_;
        delete count_;
      } else {
        (*count_)--;
      }
    }
  }
  void Release() {
    assert(*count_);
    (*count_)--;
    ptr_ = nullptr;
    count_ = nullptr;
  }
  T* Get() const { return ptr_; }
  size_t GetCount() const { return (*count_); };
  bool Unique() const { return ((*count_) == 1 && (count_)); }
  T* operator->() const { return ptr_; }
  T& operator*() const { return *ptr_; }
};

#endif  // SHARED_PTR_H_
