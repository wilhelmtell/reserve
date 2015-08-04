#ifndef RSV_RESERVE_HH_
#define RSV_RESERVE_HH_

#include <vector>
#include <cstddef>

namespace rsv {
struct reserve {
  explicit reserve(std::size_t n);

  template<typename T>
  operator std::vector<T>() const;

private:
  std::size_t n;
};
}

#include "reserve.tcc"

#endif
