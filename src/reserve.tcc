#ifndef RSV_RESERVE_TCC_
#define RSV_RESERVE_TCC_

#include <vector>
#include <utility>
#include <cstddef>

namespace rsv {
reserve::reserve(std::size_t n) : n{std::move(n)} {}

template <typename T>
reserve::operator std::vector<T>() const {
  std::vector<T> v;
  v.reserve(n);
  return v;
}
}

#endif
