#include <random>


namespace nimu {
namespace matrix {
namespace test {


class random_base {
protected:
  static std::mt19937 rng;
};

template <typename Type>
class random {
  /*
  static_assert(false, R"raw(
    Type should be "double" or "int"
  )raw");
  */
};

template<>
class random<int> final : private random_base {
public:
  random(int min, int max);

  int get() { return dist(rng); }

private:
  std::uniform_int_distribution<> dist;
};


random<int>::random(int min, int max)
  : dist{min, max}
{
}


} // test
} // matrix
} // nimu