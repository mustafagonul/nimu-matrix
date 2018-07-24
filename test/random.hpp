#include <random>


namespace nimu {
namespace matrix {
namespace test {


class random_base {
protected:
  static std::mt19937 rng;
};

std::mt19937 random_base::rng;

template <typename Type>
class random {
  static_assert(sizeof(Type) != -1, R"raw(
    Type should be "double" or "int"
  )raw");
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

template<>
class random<double> final : private random_base {
public:
  random(double min, double max);

  double get() { return dist(rng); }

private:
  std::uniform_real_distribution<double> dist;
};


} // test
} // matrix
} // nimu