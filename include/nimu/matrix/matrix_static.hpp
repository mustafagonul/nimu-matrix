#pragma once

#include <array>
#include <initializer_list>
#include <iostream>


namespace nimu {
namespace matrix {


template <typename Type, size_t RowSize, size_t ColumnSize>
class matrix_static {
public:
  using value_type = Type;
  using reference = value_type&;
  using const_reference = value_type const&;
  using size_type = size_t;
  using matrix_type = matrix_static<Type, RowSize, ColumnSize>;
  using transpose_type = matrix_static<Type, ColumnSize, RowSize>;

  template <size_t OtherColumnSize>
  using mul_param_type = matrix_static<Type, ColumnSize, OtherColumnSize>;
  template <size_t OtherColumnSize>
  using mul_result_type = matrix_static<Type, RowSize, OtherColumnSize>;

public:
  //template <typename ...E>
  //matrix_static(E&&...e) noexcept;

  matrix_static() noexcept = default;
  matrix_static(matrix_type const&) = default;
  matrix_static(matrix_type&&) noexcept = delete;
  matrix_static(std::initializer_list<value_type>) noexcept;


public:
  auto get(size_type row, size_type col) -> reference;
  auto get(size_type row, size_type col) const -> const_reference;
  auto set(size_type row, size_type col, const_reference) -> reference;

  auto add(matrix_type const &) noexcept -> matrix_type&;
  auto sub(matrix_type const &) noexcept -> matrix_type&;

  template <size_t OtherColumnSize>
  auto mul(mul_param_type<OtherColumnSize> const &) const noexcept -> mul_result_type<OtherColumnSize>;

  void mul(const_reference) noexcept;

  void fill(const_reference) noexcept;
  auto transpose() const noexcept -> transpose_type;
  bool equal(matrix_type const &) const noexcept;

  constexpr size_type row_size() const noexcept     { return row_size_;  }
  constexpr size_type column_size() const noexcept  { return column_size_; }
  constexpr size_type cell_size() const noexcept    { return cell_size_; }

private:
  constexpr size_type index(size_type row, size_type col) const noexcept {
    return row * column_size() + col;
  }

private:
  static constexpr size_type row_size_ = RowSize;
  static constexpr size_type column_size_ = ColumnSize;
  static constexpr size_type cell_size_ = row_size_ * column_size_;

  std::array<value_type, cell_size_> m_array;
};

/*
template <typename Type, size_t RowSize, size_t ColumnSize>
  template <typename ...E>
matrix_static<Type, RowSize, ColumnSize>::matrix_static(E&&...e) noexcept
  : m_array{{std::forward<E>(e)...}}
{
}
*/

template <typename Type, size_t RowSize, size_t ColumnSize>
matrix_static<Type, RowSize, ColumnSize>::matrix_static(std::initializer_list<value_type> list) noexcept
  : m_array{}
{
  auto i = m_array.begin();
  auto j = list.begin();

  for (; i != m_array.end() && j != list.end(); ++i, ++j) {
    *i = *j;
  }
}

template <typename Type, size_t RowSize, size_t ColumnSize>
inline auto matrix_static<Type, RowSize, ColumnSize>::get(size_type row, size_type col) -> reference
{
  return const_cast<reference>(static_cast<matrix_type const &>(*this).get(row, col));
}

template <typename Type, size_t RowSize, size_t ColumnSize>
inline auto matrix_static<Type, RowSize, ColumnSize>::get(size_type row, size_type col) const -> const_reference
{
  auto i = index(row, col);

  return m_array[i];
}

template <typename Type, size_t RowSize, size_t ColumnSize>
inline auto matrix_static<Type, RowSize, ColumnSize>::set(size_type row, size_type col, const_reference value) -> reference
{
  auto i = index(row, col);

  m_array[i] = value;

  return m_array;
}

template <typename Type, size_t RowSize, size_t ColumnSize>
inline auto matrix_static<Type, RowSize, ColumnSize>::add(matrix_type const&) noexcept -> matrix_type&
{
  return *this;
}


} // namespace matrix
} // namespace nimu