#ifndef CUSTOMARRAY_HPP
#define CUSTOMARRAY_HPP

#include <array>
#include <iostream>

using std::array;

template <unsigned int N>
bool operator>(const std::array<char, N>& lhs, const std::array<char, N>& rhs) {
  int lhs_val = 0;
  int rhs_val = 0;
  for (unsigned i = 0; i < N; i++) {
    lhs_val += lhs[i];
    rhs_val += rhs[i];
  }
  return lhs_val > rhs_val;
}

template <unsigned int N>
bool operator<(const std::array<char, N>& lhs, const std::array<char, N>& rhs) {
  int lhs_val = 0;
  int rhs_val = 0;
  for (unsigned i = 0; i < N; i++) {
    lhs_val += lhs[i];
    rhs_val += rhs[i];
  }
  return lhs_val < rhs_val;
}

std::ostream& operator<<(std::ostream& lhs, const std::array<char, 3>& rhs) {
  lhs << '[';
	for (unsigned int i = 0; i < 3; i++) {
    lhs << rhs[i];
    if (i != 2) lhs << ',';
  }
	lhs << ']';
  return lhs;
}

template <typename T, unsigned int N>
class set {
 private:
  std::array<T, N> array;
  unsigned int length_arr = 0;

  bool contains(T search_val) {
    for (unsigned int i = 0; i < length_arr; i++) {
      if (array[i] == search_val) return true;
    }
    return false;
  }

 public:
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

  T max() {
    if (length_arr > 0) {
      T max_val = array[0];
      for (unsigned int i = 1; i < length_arr; i++) {
        if (array[i] > max_val) max_val = array[i];
      }
      return max_val;
    } else {
      return 0;
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