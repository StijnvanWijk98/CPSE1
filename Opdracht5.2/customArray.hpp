#ifndef CUSTOMARRAY_HPP
#define CUSTOMARRAY_HPP

#include <array>
#include <iostream>

template<typename T, unsigned int N>
class set {
 private:
  std::array<T, N> array = {};
  unsigned int length_arr;

  bool contains(T search_val) {
    for (unsigned int i = 0; i < length_arr; i++) {
      if (array[i] == search_val) return true;
    }
    return false;
  }

 public:
  set() : length_arr(0) {}

  void add(T to_add) {
    if (!contains(to_add) && length_arr < N) {
      array[length_arr] = to_add;
      length_arr++;
    }
  }

  void remove(T to_remove) {
    for (unsigned int i = 0; i < length_arr; i++) {
      if (array[i] == to_remove) {
        length_arr--;
        array[i] = array[length_arr];
      }
    }
  }

  friend std::ostream& operator<<(std::ostream& lhs, const set& rhs) {
    for (unsigned int i = 0; i < rhs.length_arr; i++) {
      lhs << rhs.array[i];
      if (i != rhs.length_arr - 1) lhs << ",";
    }
    return lhs;
  }
};

#endif