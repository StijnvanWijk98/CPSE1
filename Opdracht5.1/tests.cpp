#include "customArray.hpp"
#include <sstream>
#include "catch.hpp"

using std::stringstream;

TEST_CASE("constructor"){
	set v = set();
	stringstream s;
	s << v;
	REQUIRE(s.str() == "");
}

TEST_CASE("add, no duplicate"){
	set v = set();
	stringstream s;
	v.add(3);
	s << v;
	REQUIRE(s.str() == "3");
}

TEST_CASE("add, duplicate"){
	set v = set();
	stringstream s;
	v.add(5);
	v.add(5);
	s << v;
	REQUIRE(s.str() == "5");
}

TEST_CASE("add, full"){
	set v = set();
	stringstream s;
	for(int i = 0; i <= 10; i++){
		v.add(i);
	}
	s << v;
	REQUIRE(s.str() == "0,1,2,3,4,5,6,7,8,9");
}

TEST_CASE("remove, in array"){
	set v = set();
	stringstream s1;
	stringstream s2;
	v.add(3);
	s1 << v;
	REQUIRE(s1.str() == "3");
	v.remove(3);
	s2 << v;
	REQUIRE(s2.str() == "");
}

TEST_CASE("remove, not in array"){
	set v = set();
	stringstream s1;
	stringstream s2;
	v.add(3);
	s1 << v;
	REQUIRE(s1.str() == "3");
	v.remove(5);
	s2 << v;
	REQUIRE(s2.str() == "3");
}
