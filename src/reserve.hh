#ifndef RSV_RESERVE_HH_
#define RSV_RESERVE_HH_

#include <vector>

namespace rsv {
struct reserve {
  explicit reserve(std::vector<int>::size_type n);

  template<typename T>
  operator std::vector<T>() const;

private:
  std::vector<int>::size_type n;
};
}

#include "reserve.tcc"

#endif
