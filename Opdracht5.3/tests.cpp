#include <sstream>
#include "catch.hpp"
#include "customArray.hpp"

using std::stringstream;

TEST_CASE("constructor : template <int,1>") {
  set v = set<int, 1>();
  stringstream s;
  s << v;
  REQUIRE(s.str() == "");
}

TEST_CASE("constructor : template <char,26>") {
  set v = set<char, 26>();
  stringstream s;
  s << v;
  REQUIRE(s.str() == "");
}

TEST_CASE("add, no duplicate : template <float,5>") {
  set v = set<float, 5>();
  stringstream s;
  v.add(3.43);
  s << v;
  REQUIRE(s.str() == "3.43");
}

TEST_CASE("add, duplicate : template <float,3>") {
	set v = set<float, 3>();
	stringstream s;
	v.add(5.54);
	v.add(5.54);
	v.add(5.23);
	s << v;
	REQUIRE(s.str() == "5.54,5.23");
}

TEST_CASE("add, no duplicate : template <char,5>") {
  set v = set<char, 5>();
  stringstream s;
  v.add('h');
	v.add('!');
  s << v;
  REQUIRE(s.str() == "h,!");
}

TEST_CASE("add, duplicate : template <char, 4>") {
  set v = set<char, 4>();
  stringstream s;
  v.add('a');
  v.add('a');
  s << v;
  REQUIRE(s.str() == "a");
}

TEST_CASE("add, full : template <int, 7>") {
  set v = set<int, 7>();
  stringstream s;
  for (int i = 0; i <= 7; i++) {
    v.add(i);
  }
  s << v;
  REQUIRE(s.str() == "0,1,2,3,4,5,6");
}

TEST_CASE("add, full : template <float, 5>") {
  set v = set<float, 5>();
  stringstream s;
  for (int i = 1; i <= 6; i++) {
    v.add((i+i*0.1));
  }
  s << v;
  REQUIRE(s.str() == "1.1,2.2,3.3,4.4,5.5");
}

TEST_CASE("remove, in array : template <char, 26>") {
  set v = set<char, 26>();
  stringstream s1;
  stringstream s2;
  v.add('a');
	v.add('n');
	v.add('o');
	v.add('g');
  s1 << v;
  REQUIRE(s1.str() == "a,n,o,g");
  v.remove('n');
  s2 << v;
  REQUIRE(s2.str() == "a,g,o");
}

TEST_CASE("remove, not in array : template <int, 5>") {
  set v = set<int, 5>();
  stringstream s1;
  stringstream s2;
  v.add(3);
  s1 << v;
  REQUIRE(s1.str() == "3");
  v.remove(5);
  s2 << v;
  REQUIRE(s2.str() == "3");
}

TEST_CASE("max, filled array : template<int, 9>") {
  set v = set<int, 9>();
  stringstream s1;
	v.add(6);
	v.add(4);
	v.add(7);
	v.add(2);
  s1 << v.max();
  REQUIRE(s1.str() == "7");
}

TEST_CASE("max, filled array : template<char, 14>") {
  set v = set<char, 14>();
  stringstream s1;
	v.add('!');
	v.add('P');
	v.add('h');
	v.add('Q');
	v.add('y');
  s1 << v.max();
  REQUIRE(s1.str() == "y");
}

TEST_CASE("max, empty array : template<float, 4>") {
  set v = set<float, 4>();
  stringstream s1;
  s1 << v.max();
  REQUIRE(s1.str() == "0");
}

TEST_CASE("max, empty array : template<char, 8>") {
  set v = set<char, 8>();
  stringstream s1;
	stringstream s2;
  s1 << v.max();
	s2 << char(0);
  REQUIRE(s1.str() == s2.str());
}

TEST_CASE("max, negative array : template<int,6>"){
	set v = set<int, 6>();
  stringstream s1;
	v.add(-5);
	v.add(-14);
	v.add(-3);
	v.add(-7);
  s1 << v.max();
  REQUIRE(s1.str() == "-3");
}

// TEST_CASE(",  : template<,>") {
//   set v = set<int, 5>();
//   stringstream s1;

//   s1 << v;
//   REQUIRE(s1.str() == "");
// }
