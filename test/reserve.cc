#include <catch/catch.hpp>
#include "../src/reserve.hh"
#include <vector>

TEST_CASE("reserve{5} vector has capacity >= 5") {
  auto const x = 5;
  auto const a = std::vector<int>(rsv::reserve{5}).capacity();
  REQUIRE(x <= a);
}

TEST_CASE("reserve{0} vector has capacity >= 0") {
  auto const x = 0;
  auto const a = std::vector<int>(rsv::reserve{0}).capacity();
  REQUIRE(x <= a);
}

TEST_CASE("reserve{500} vector has capacity >= 500") {
  auto const x = 500;
  auto const a = std::vector<int>(rsv::reserve{500}).capacity();
  REQUIRE(x <= a);
}

TEST_CASE("construct a reserved vector without auto") {
  auto const x = 500;
  std::vector<int> const v(rsv::reserve{500});
  REQUIRE(x <= v.capacity());
}
