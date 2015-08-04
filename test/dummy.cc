#include <catch/catch.hpp>
#include "../src/dummy.hh"

TEST_CASE("dummy mutates from 42 to 21") {
  // arrange
  dmy::dummy d{42};

  // act
  d.mutate();

  // assert
  REQUIRE(21 == d.get());
}
