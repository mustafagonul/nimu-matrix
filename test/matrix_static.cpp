#define BOOST_TEST_MODULE nimu_matrix_test_matrix_static
#include <boost/test/unit_test.hpp>

#include <nimu/matrix/matrix_static.hpp>

namespace utf = boost::unit_test;
namespace nmx = nimu::matrix;


BOOST_AUTO_TEST_SUITE(matrix_static)

BOOST_AUTO_TEST_CASE(constructor_1)
{
  using matrix_type = nimu::matrix::matrix_static<double, 2, 2>;

  matrix_type matrix;

  BOOST_CHECK_EQUAL(matrix.row_size(), 2);
  BOOST_CHECK_EQUAL(matrix.column_size(), 2);
}

BOOST_AUTO_TEST_CASE(constructor_2, * utf::tolerance(0.000001))
{
  using matrix_type = nimu::matrix::matrix_static<double, 2, 2>;

  //matrix_type matrix(1.0, 1.0, 2.0, 3.0);
  matrix_type matrix({1.0, 2.0, 3.0, 4.0});

  BOOST_CHECK_EQUAL(matrix.get(0, 0), 1.0);
  BOOST_CHECK_EQUAL(matrix.get(0, 1), 2.0);
  BOOST_CHECK_EQUAL(matrix.get(1, 0), 3.0);
  BOOST_CHECK_EQUAL(matrix.get(1, 1), 4.0);
}

BOOST_AUTO_TEST_CASE(constructor_3, * utf::tolerance(0.000001))
{
  using matrix_type = nimu::matrix::matrix_static<double, 2, 2>;

  matrix_type matrix{1.0, 2.0, 3.0, 4.0};

  BOOST_CHECK_EQUAL(matrix.get(0, 0), 1.0);
  BOOST_CHECK_EQUAL(matrix.get(0, 1), 2.0);
  BOOST_CHECK_EQUAL(matrix.get(1, 0), 3.0);
  BOOST_CHECK_EQUAL(matrix.get(1, 1), 4.0);
}

BOOST_AUTO_TEST_CASE(constructor_4, * utf::tolerance(0.000001))
{
  using matrix_type = nimu::matrix::matrix_static<double, 2, 2>;

  matrix_type matrix = {1.0, 2.0, 3.0, 4.0};

  BOOST_CHECK_EQUAL(matrix.get(0, 0), 1.0);
  BOOST_CHECK_EQUAL(matrix.get(0, 1), 2.0);
  BOOST_CHECK_EQUAL(matrix.get(1, 0), 3.0);
  BOOST_CHECK_EQUAL(matrix.get(1, 1), 4.0);
}

BOOST_AUTO_TEST_CASE(constructor_5, * utf::tolerance(0.000001))
{
  using matrix_type = nimu::matrix::matrix_static<double, 2, 2>;

  matrix_type matrix = {1.0, 2.0, 3.0};

  BOOST_CHECK_EQUAL(matrix.get(0, 0), 1.0);
  BOOST_CHECK_EQUAL(matrix.get(0, 1), 2.0);
  BOOST_CHECK_EQUAL(matrix.get(1, 0), 3.0);
  BOOST_CHECK_EQUAL(matrix.get(1, 1), 0.0);
}

BOOST_AUTO_TEST_CASE(constructor_6, * utf::tolerance(0.000001))
{
  using matrix_type = nimu::matrix::matrix_static<double, 2, 2>;

  matrix_type matrix = {1.0, 2.0, 3.0, 4.0, 5.0};

  BOOST_CHECK_EQUAL(matrix.get(0, 0), 1.0);
  BOOST_CHECK_EQUAL(matrix.get(0, 1), 2.0);
  BOOST_CHECK_EQUAL(matrix.get(1, 0), 3.0);
  BOOST_CHECK_EQUAL(matrix.get(1, 1), 4.0);
}

BOOST_AUTO_TEST_CASE(copy_constructor_1)
{
  using matrix_type = nimu::matrix::matrix_static<double, 2, 2>;

  matrix_type matrix;
  auto other = matrix;

  BOOST_CHECK_EQUAL(matrix.row_size(), 2);
  BOOST_CHECK_EQUAL(matrix.column_size(), 2);
}

BOOST_AUTO_TEST_CASE(copy_constructor_2, * utf::tolerance(0.000001))
{
  using matrix_type = nimu::matrix::matrix_static<double, 2, 2>;

  matrix_type matrix = {1.0, 2.0, 3.0, 4.0};
  auto other = matrix;

  BOOST_CHECK_EQUAL(other.get(0, 0), 1.0);
  BOOST_CHECK_EQUAL(other.get(0, 1), 2.0);
  BOOST_CHECK_EQUAL(other.get(1, 0), 3.0);
  BOOST_CHECK_EQUAL(other.get(1, 1), 4.0);
}


BOOST_AUTO_TEST_SUITE_END()

