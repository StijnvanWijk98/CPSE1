#ifndef CUSTOMMATH_HPP
#define CUSTOMMATH_HPP

template <typename T>
constexpr T pow(T base, int pow) {
  T res = 1;
  while (pow > 0) {
    res *= base;
    --pow;
  }
  return res;
}

template <typename T>
constexpr T fac(T fac) {
  T res = 1;
  while (fac > 0) {
    res *= fac;
    --fac;
  }
  return res;
}

constexpr double sin(double x) {
  return x - pow(x, 3) / fac(3.0) + pow(x, 5) / fac(5.0) - pow(x, 7) / fac(7.0) + pow(x, 9) / fac(9.0) -
         pow(x, 11) / fac(11.0) + pow(x, 13) / fac(13.0) - pow(x, 15) / fac(15.0) + pow(x, 17) / fac(17.0) -
         pow(x, 19) / fac(19.0) + pow(x, 21) / fac(21.0) - pow(x, 23) / fac(23.0) + pow(x, 25) / fac(25.0) -
         pow(x, 27) / fac(27.0) + pow(x, 29) / fac(29.0);
}

constexpr double cos(double x) {
  return 1 - pow(x, 2) / fac(2.0) + pow(x, 4) / fac(4.0) - pow(x, 6) / fac(6.0) + pow(x, 8) / fac(8.0) - pow(x, 10) / fac(10.0) +
         pow(x, 12) / fac(12.0) - pow(x, 14) / fac(14.0) + pow(x, 16) / fac(16.0) - pow(x, 18) / fac(18.0) +
         pow(x, 20) / fac(20.0) - pow(x, 22) / fac(22.0) + pow(x, 24) / fac(24.0) - pow(x, 26) / fac(26.0) +
         pow(x, 28) / fac(28.0);
}

#endif