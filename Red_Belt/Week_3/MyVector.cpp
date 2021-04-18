#pragma once

#include algorithm
using namespace std;

template typename T
class SimpleVector {
public
  SimpleVector() = default;
  explicit SimpleVector(size_t size);
  ~SimpleVector();

  T& operator[](size_t index);

  T begin();
  T end();

  size_t Size() const;
  size_t Capacity() const;
  void PushBack(const T& value);

private
  T data = nullptr;
  size_t size = 0;
  size_t capacity = 0;
};

template typename T
SimpleVectorTSimpleVector(size_t size)
   data(new T[size])
  , size(size)
  , capacity(size)
{
}

template typename T
SimpleVectorT~SimpleVector() {
  delete[] data;
}

template typename T
T& SimpleVectorToperator[](size_t index) {
  return data[index];
}

template typename T
size_t SimpleVectorTSize() const {
  return size;
}

template typename T
size_t SimpleVectorTCapacity() const {
  return capacity;
}

template typename T
void SimpleVectorTPushBack(const T& value) {
  if (size = capacity) {
    auto new_cap = capacity == 0  1  2  capacity;
    auto new_data = new T[new_cap];
    copy(begin(), end(), new_data);
    delete[] data;
    data = new_data;
    capacity = new_cap;
  }
  data[size++] = value;
}

template typename T
T SimpleVectorTbegin() {
  return data;
}

template typename T
T SimpleVectorTend() {
  return data + size;
}
