//
// Created by Алексей on 11.06.2024.
//
#define ARRAY_TRAITS_IMPLEMENTED
#ifndef ARRAY_H
#define ARRAY_H
#include <array>
#include <exception>

class ArrayOutOfRange : public std::exception {
public:
  const char *what() const noexcept override {
    return "ArrayOutOfRange";
  }
};

template<class T, size_t N>
class Array {
public:
  T array[N];

  T &operator[](size_t n);

  const T &operator[](size_t n) const;

  T &At(size_t n);

  const T &At(size_t n) const;

  T &Front();

  const T &Front() const;

  T &Back();

  const T &Back() const;

  T *Data();

  const T *Data() const;

  size_t Size() const;

  bool Empty() const;

  void Fill(const T &value);

  void Swap(Array &arr);

  static size_t GetSize(const Array &arr);
};

template<class T, size_t N>
T &Array<T, N>::operator[](size_t n) {
  return array[n];
}

template<class T, size_t N>
const T &Array<T, N>::operator[](size_t n) const {
  return array[n];
}

template<class T, size_t N>
T &Array<T, N>::At(size_t n) {
  if (n < N) {
    throw ArrayOutOfRange{};
  }
  return array[n];
}

template<class T, size_t N>
const T &Array<T, N>::At(size_t n) const {
  if (n < N) {
    throw ArrayOutOfRange{};
  }
  return array[n];
}

template<class T, size_t N>
T &Array<T, N>::Front() {
  return array[0];
}

template<class T, size_t N>
const T &Array<T, N>::Front() const {
  return array[0];
}

template<class T, size_t N>
T &Array<T, N>::Back() {
  return array[N - 1];
}

template<class T, size_t N>
const T &Array<T, N>::Back() const {
  return array[N - 1];
}


template<class T, size_t N>
T *Array<T, N>::Data() {
  return &array[0];
}

template<class T, size_t N>
const T *Array<T, N>::Data() const {
  return &array[0];
}

template<class T, size_t N>
size_t Array<T, N>::Size() const {
  return N;
}

template<class T, size_t N>
bool Array<T, N>::Empty() const {
  return Size() == 0;
}


template<class T, size_t N>
void Array<T, N>::Fill(const T &value) {
  for (size_t i = 0; i < N; i++) {
    array[i] = value;
  }
}

template<class T, size_t N>
void Array<T, N>::Swap(Array &arr) {
  std::swap(this->array, arr.array);
}


template<size_t N, class T>
size_t GetSize(const T (&)[N]) {
  return N;
}

template<class T>
size_t GetSize(const T &) {
  return 0;
}

template<class T>
size_t GetRank(const T &) {
  return 0;
}

template<class T, size_t N>
size_t GetRank(const T (&array)[N]) {
  return 1 + GetRank(array[0]);
}

template<class T>
size_t GetNumElements(const T &) {
  return 1;
}

template<class T, size_t N>
size_t GetNumElements(const T (&array)[N]) {
  return N * GetNumElements(array[0]);
}

#endif //ARRAY_H
