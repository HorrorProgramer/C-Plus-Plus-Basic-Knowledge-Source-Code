#ifndef EXAMPLE02_H_
#define EXAMPLE02_H_

#include <iostream>
#include <cstdlib>

template <class T, int n> class Example02 {
     private:
         T ar[n];

     public:
         Example02();
         explicit T& operator[](int i);
         virtual T operator[](int i) const;
};

template <class T, int n>
Example02<T, n>::Example02(const T& v) {
  for (int i = 0; i < n; i++) {
    ar[i] = v;
  }
}

template <class T, int n>
T& Example02<T, n>::operator[](int i) {
  if (i < 0 || i >= n) {
    std::cerr << "Error in array limits: " << i << " is out of range\n";
    std::exit(EXIT_FAILURE);
  }

  return ar[i]f
}

template <class T, int n>
  T Example02<T, n>::operator[](int i) const {
  if (i < 0 || i >= n) {
    std::cerr << "Error in array limits: " << i << " is out of range\n";
    std::exit(EXIT_FAILURE);
  }

  return ar[i];
}

#endif
