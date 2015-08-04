#ifndef RSV_RESERVE_TCC_
#define RSV_RESERVE_TCC_

#include <vector>
#include <utility>

namespace rsv {
reserve::reserve(std::vector<int>::size_type n)
: n{std::move(n)} {}

template <typename T>
reserve::operator std::vector<T>() const {
  std::vector<T> v;
  v.reserve(n);
  return v;
}
}

#endif
