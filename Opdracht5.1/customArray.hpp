#ifndef CUSTOMARRAY_HPP
#define CUSTOMARRAY_HPP

#include <array>
#include <iostream>

class set {
 private:
  std::array<int, 10> array = {};
  int length_arr;

  bool contains(int search_val) {
    for (int i = 0; i < length_arr; i++) {
      if (array[i] == search_val) return true;
    }
    return false;
  }

 public:
  set() : length_arr(0) {}

  void add(int to_add) {
    if (!contains(to_add) && length_arr < 10) {
      array[length_arr] = to_add;
      length_arr++;
    }
  }

  void remove(int to_remove) {
    for (int i = 0; i < length_arr; i++) {
      if (array[i] == to_remove) {
        array[i] = array[length_arr-1];
        length_arr--;
      }
    }
  }

  friend std::ostream& operator<<(std::ostream& lhs, const set& rhs) {
    for (int i = 0; i < rhs.length_arr; i++) {
      lhs << rhs.array[i];
      if (i != rhs.length_arr - 1) lhs << ",";
    }
    return lhs;
  }
};

#endif