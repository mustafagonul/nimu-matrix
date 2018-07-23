#define BOOST_TEST_MODULE nimu_matrix_test_matrix_static
#include <boost/test/unit_test.hpp>
#include <boost/numeric/ublas/matrix.hpp>

#include <nimu/matrix/matrix_static.hpp>
// #include <nimu/matrix/test/random.hpp>
#include "random.hpp"


namespace utf = boost::unit_test;
namespace bnu = boost::numeric::ublas;
namespace nmx = nimu::matrix;
namespace nmt = nimu::matrix::test;


BOOST_AUTO_TEST_SUITE(matrix_static)

BOOST_AUTO_TEST_CASE(constructor_1)
{
  using matrix_type = nmx::matrix_static<double, 2, 2>;

  matrix_type matrix;

  BOOST_CHECK_EQUAL(matrix.row_size(), 2);
  BOOST_CHECK_EQUAL(matrix.column_size(), 2);
}

BOOST_AUTO_TEST_CASE(constructor_2, * utf::tolerance(0.000001))
{
  using matrix_type = nmx::matrix_static<double, 2, 2>;

  //matrix_type matrix(1.0, 1.0, 2.0, 3.0);
  matrix_type matrix({1.0, 2.0, 3.0, 4.0});

  BOOST_CHECK_EQUAL(matrix.get(0, 0), 1.0);
  BOOST_CHECK_EQUAL(matrix.get(0, 1), 2.0);
  BOOST_CHECK_EQUAL(matrix.get(1, 0), 3.0);
  BOOST_CHECK_EQUAL(matrix.get(1, 1), 4.0);
}

BOOST_AUTO_TEST_CASE(constructor_3, * utf::tolerance(0.000001))
{
  using matrix_type = nmx::matrix_static<double, 2, 2>;

  matrix_type matrix{1.0, 2.0, 3.0, 4.0};

  BOOST_CHECK_EQUAL(matrix.get(0, 0), 1.0);
  BOOST_CHECK_EQUAL(matrix.get(0, 1), 2.0);
  BOOST_CHECK_EQUAL(matrix.get(1, 0), 3.0);
  BOOST_CHECK_EQUAL(matrix.get(1, 1), 4.0);
}

BOOST_AUTO_TEST_CASE(constructor_4, * utf::tolerance(0.000001))
{
  using matrix_type = nmx::matrix_static<double, 2, 2>;

  matrix_type matrix = {1.0, 2.0, 3.0, 4.0};

  BOOST_CHECK_EQUAL(matrix.get(0, 0), 1.0);
  BOOST_CHECK_EQUAL(matrix.get(0, 1), 2.0);
  BOOST_CHECK_EQUAL(matrix.get(1, 0), 3.0);
  BOOST_CHECK_EQUAL(matrix.get(1, 1), 4.0);
}

BOOST_AUTO_TEST_CASE(constructor_5, * utf::tolerance(0.000001))
{
  using matrix_type = nmx::matrix_static<double, 2, 2>;

  matrix_type matrix = {1.0, 2.0, 3.0};

  BOOST_CHECK_EQUAL(matrix.get(0, 0), 1.0);
  BOOST_CHECK_EQUAL(matrix.get(0, 1), 2.0);
  BOOST_CHECK_EQUAL(matrix.get(1, 0), 3.0);
  BOOST_CHECK_EQUAL(matrix.get(1, 1), 0.0);
}

BOOST_AUTO_TEST_CASE(constructor_6, * utf::tolerance(0.000001))
{
  using matrix_type = nmx::matrix_static<double, 2, 2>;

  matrix_type matrix = {1.0, 2.0, 3.0, 4.0, 5.0};

  BOOST_CHECK_EQUAL(matrix.get(0, 0), 1.0);
  BOOST_CHECK_EQUAL(matrix.get(0, 1), 2.0);
  BOOST_CHECK_EQUAL(matrix.get(1, 0), 3.0);
  BOOST_CHECK_EQUAL(matrix.get(1, 1), 4.0);
}

BOOST_AUTO_TEST_CASE(copy_constructor_1)
{
  using matrix_type = nmx::matrix_static<double, 2, 2>;

  matrix_type matrix;
  auto other = matrix;

  BOOST_CHECK_EQUAL(other.row_size(), 2);
  BOOST_CHECK_EQUAL(other.column_size(), 2);
}

BOOST_AUTO_TEST_CASE(copy_constructor_2, * utf::tolerance(0.000001))
{
  using matrix_type = nmx::matrix_static<double, 2, 2>;

  matrix_type matrix = {1.0, 2.0, 3.0, 4.0};
  auto other = matrix;

  BOOST_CHECK_EQUAL(other.get(0, 0), 1.0);
  BOOST_CHECK_EQUAL(other.get(0, 1), 2.0);
  BOOST_CHECK_EQUAL(other.get(1, 0), 3.0);
  BOOST_CHECK_EQUAL(other.get(1, 1), 4.0);
}

BOOST_AUTO_TEST_CASE(assignment, * utf::tolerance(0.000001))
{
  using matrix_type = nmx::matrix_static<double, 2, 2>;

  matrix_type matrix = {1.0, 2.0, 3.0, 4.0};

  BOOST_CHECK_EQUAL(matrix.get(0, 0), 1.0);
  BOOST_CHECK_EQUAL(matrix.get(0, 1), 2.0);
  BOOST_CHECK_EQUAL(matrix.get(1, 0), 3.0);
  BOOST_CHECK_EQUAL(matrix.get(1, 1), 4.0);

  matrix_type other = {5.0, 6.0, 7.0, 8.0};

  BOOST_CHECK_EQUAL(other.get(0, 0), 5.0);
  BOOST_CHECK_EQUAL(other.get(0, 1), 6.0);
  BOOST_CHECK_EQUAL(other.get(1, 0), 7.0);
  BOOST_CHECK_EQUAL(other.get(1, 1), 8.0);

  other = matrix;

  BOOST_CHECK_EQUAL(other.get(0, 0), 1.0);
  BOOST_CHECK_EQUAL(other.get(0, 1), 2.0);
  BOOST_CHECK_EQUAL(other.get(1, 0), 3.0);
  BOOST_CHECK_EQUAL(other.get(1, 1), 4.0);
}

BOOST_AUTO_TEST_CASE(get_1, * utf::tolerance(0.000001))
{
  using matrix_type = nmx::matrix_static<double, 2, 2>;

  matrix_type matrix = {1.0, 2.0, 3.0, 4.0};

  BOOST_CHECK_EQUAL(matrix.get(0), 1.0);
  BOOST_CHECK_EQUAL(matrix.get(1), 2.0);
  BOOST_CHECK_EQUAL(matrix.get(2), 3.0);
  BOOST_CHECK_EQUAL(matrix.get(3), 4.0);
}

BOOST_AUTO_TEST_CASE(get_2, * utf::tolerance(0.000001))
{
  using matrix_type = nmx::matrix_static<double, 2, 2>;

  matrix_type matrix = {1.0, 2.0, 3.0, 4.0};

  BOOST_CHECK_EQUAL(matrix.get(0, 0), 1.0);
  BOOST_CHECK_EQUAL(matrix.get(0, 1), 2.0);
  BOOST_CHECK_EQUAL(matrix.get(1, 0), 3.0);
  BOOST_CHECK_EQUAL(matrix.get(1, 1), 4.0);
}

BOOST_AUTO_TEST_CASE(set_1, * utf::tolerance(0.000001))
{
  using matrix_type = nmx::matrix_static<double, 2, 2>;

  matrix_type matrix = {1.0, 2.0, 3.0, 4.0};

  BOOST_CHECK_EQUAL(matrix.get(0), 1.0);
  BOOST_CHECK_EQUAL(matrix.get(1), 2.0);
  BOOST_CHECK_EQUAL(matrix.get(2), 3.0);
  BOOST_CHECK_EQUAL(matrix.get(3), 4.0);

  matrix.set(0) = 5.0;
  matrix.set(1) = 6.0;
  matrix.set(2) = 7.0;
  matrix.set(3) = 8.0;

  BOOST_CHECK_EQUAL(matrix.get(0), 5.0);
  BOOST_CHECK_EQUAL(matrix.get(1), 6.0);
  BOOST_CHECK_EQUAL(matrix.get(2), 7.0);
  BOOST_CHECK_EQUAL(matrix.get(3), 8.0);
}

BOOST_AUTO_TEST_CASE(set_2, * utf::tolerance(0.000001))
{
  using matrix_type = nmx::matrix_static<double, 2, 2>;

  matrix_type matrix = {1.0, 2.0, 3.0, 4.0};

  BOOST_CHECK_EQUAL(matrix.get(0, 0), 1.0);
  BOOST_CHECK_EQUAL(matrix.get(0, 1), 2.0);
  BOOST_CHECK_EQUAL(matrix.get(1, 0), 3.0);
  BOOST_CHECK_EQUAL(matrix.get(1, 1), 4.0);

  matrix.set(0, 0) = 5.0;
  matrix.set(0, 1) = 6.0;
  matrix.set(1, 0) = 7.0;
  matrix.set(1, 1) = 8.0;

  BOOST_CHECK_EQUAL(matrix.get(0, 0), 5.0);
  BOOST_CHECK_EQUAL(matrix.get(0, 1), 6.0);
  BOOST_CHECK_EQUAL(matrix.get(1, 0), 7.0);
  BOOST_CHECK_EQUAL(matrix.get(1, 1), 8.0);
}

/*
BOOST_AUTO_TEST_CASE(add_1, * utf::tolerance(0.000001))
{
  using value_type = double;
  constexpr size_t row = 10;
  constexpr size_t column = 10;
  using matrix_type = nmx::matrix_static<value_type, row, column>;
  using other_type = bnu::matrix<double>;

  nmt::random<int> rand(1, 10);

  matrix_type matrix;
  for (size_t i = 0; i < row; ++i) {
    for (size_t j = 0; j < column; ++j) {
      auto value = rand.get();
    }
  }


}
*/


BOOST_AUTO_TEST_SUITE_END()

