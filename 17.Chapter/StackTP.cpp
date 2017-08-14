#include "StackTP.h"

template <class Type>
Stack<Type>::Stack(): top(0) {}

template <class Type>
bool Stack<Type>::isEmpty() const  {
    return top == 0;
}

template <class Type>
bool Stack<Type>::isFull() const {
    return top == Max;
}

template <class Type>
bool Stack<Type>::push(const Type& type) {
  if (top < Max) {
    items[top++] = type;
    return true;
  }
    
  return false;
}

template <class Type>
bool Stack<Type>::pop(Type& type) {
  if (top > 0) {
    type = items[top--];
    return true;
  }
   
  return false;
}
