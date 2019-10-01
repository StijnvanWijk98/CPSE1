#ifndef LOOKUP_HPP
#define LOOKUP_HPP

// #include "cmath"
#include "customMath.hpp"
#include "hwlib.hpp"

#define pi_approach 3.1415926535897932

using hwlib::cout;
using hwlib::endl;
using std::array;

constexpr double radiansToDegrees(int deg) { return 2.0 * pi_approach * (deg / 360.0); }

constexpr int scaledSinFromDegrees(int deg, int scale = 30) {
  return scale * sin(radiansToDegrees(deg));
}
constexpr int scaledCosFromDegrees(int deg, int scale = 30) {
  return scale * cos(radiansToDegrees(deg));
}

constexpr double sinFromDeg(int deg){
	return sin(radiansToDegrees(deg));
}

constexpr double cosFromDeg(int deg){
	return cos(radiansToDegrees(deg));
}

template <int N, typename T>
class lookup {
 private:
  array<T, N> values = {};

 public:
  constexpr lookup() {}
  template <typename F>
  constexpr lookup(F function) {
    for (int i = 0; i < N; i++) {
      values[i] = function(i);
    }
  }

  constexpr T get(int n) const { return values[n]; }
};

#endif