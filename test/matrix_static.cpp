#define BOOST_TEST_MODULE nimu_matrix_test_matrix_static
#include <boost/test/unit_test.hpp>

#include <nimu/matrix/matrix_static.hpp>

//using namespace nimu::matrix;


BOOST_AUTO_TEST_SUITE(matrix_static)

BOOST_AUTO_TEST_CASE(constructor_1)
{
  using matrix_type = nimu::matrix::matrix_static<double, 2, 2>;

  matrix_type matrix;

  BOOST_TEST(true);
}

BOOST_AUTO_TEST_CASE(constructor_2)
{
  using matrix_type = nimu::matrix::matrix_static<double, 2, 2>;

  matrix_type matrix = {0.0, 1.0, 2.0, 3.0};

  BOOST_TEST(true);
}

BOOST_AUTO_TEST_SUITE_END()

