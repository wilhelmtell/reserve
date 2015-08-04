#include <catch/catch.hpp>
#include "../src/reserve.hh"
#include <vector>

TEST_CASE("reserve{5} vector has capacity >= 5") {
  auto const x = 5;
  auto const a = std::vector<int>(rsv::reserve{5}).capacity();
  REQUIRE(x <= a);
}
