#ifndef DMY_DUMMY_HH_
#define DMY_DUMMY_HH_

namespace dmy {
struct dummy {
  dummy() = default;
  explicit dummy(int value);

  int get() const;
  void mutate();

private:
  int value;
};
}

#endif
