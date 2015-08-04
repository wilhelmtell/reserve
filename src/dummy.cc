#include "dummy.hh"

namespace dmy {
dummy::dummy(int value) : value(value) {}

int dummy::get() const { return value; }

void dummy::mutate() {
  value = value == 1 ? value : value % 2 == 0 ? value / 2 : value * 3 + 1;
}
}
