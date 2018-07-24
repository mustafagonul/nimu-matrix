#pragma once

#include <array>
#include <initializer_list>


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
  matrix_static(matrix_type&&) noexcept = delete;
  matrix_static(matrix_type const&) noexcept = default;
  matrix_static(std::initializer_list<value_type>) noexcept;

  matrix_static&& operator=(matrix_static&&) = delete;
  matrix_static& operator=(matrix_static const&) = default;

public:
  auto get(size_type) const -> const_reference;
  auto get(size_type row, size_type col) const -> const_reference;
  auto set(size_type index) -> reference;
  auto set(size_type row, size_type col) -> reference;

  auto add(matrix_type const &) noexcept -> matrix_type&;
  auto sub(matrix_type const &) noexcept -> matrix_type&;

  template <size_t OtherColumnSize>
  auto mul(mul_param_type<OtherColumnSize> const &) const noexcept -> mul_result_type<OtherColumnSize>;

  void mul(const_reference) noexcept;

  void fill(const_reference) noexcept;
  auto transpose() const noexcept -> transpose_type;
  bool equal(matrix_type const &) const noexcept;

  auto operator()(size_type index) noexcept -> reference              { return set(index);    }
  auto operator()(size_type row, size_type col) noexcept -> reference { return set(row, col); }

  constexpr size_type size() const noexcept         { return size_; }
  constexpr size_type row_size() const noexcept     { return row_size_;  }
  constexpr size_type column_size() const noexcept  { return column_size_; }

private:
  constexpr size_type index(size_type row, size_type col) const noexcept {
    return row * column_size() + col;
  }

private:
  static constexpr size_type row_size_ = RowSize;
  static constexpr size_type column_size_ = ColumnSize;
  static constexpr size_type size_ = row_size_ * column_size_;

  std::array<value_type, size_> m_array;
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
inline auto matrix_static<Type, RowSize, ColumnSize>::get(size_type index) const -> const_reference
{
  // Throws std::out_of_range
  // return m_array.at(index);

  // Throws no wxception
  return m_array[index];
}

template <typename Type, size_t RowSize, size_t ColumnSize>
inline auto matrix_static<Type, RowSize, ColumnSize>::get(size_type row, size_type col) const -> const_reference
{
  auto i = index(row, col);

  return get(i);
}

template <typename Type, size_t RowSize, size_t ColumnSize>
inline auto matrix_static<Type, RowSize, ColumnSize>::set(size_type index) -> reference
{
  return const_cast<reference>(static_cast<matrix_type const &>(*this).get(index));
}

template <typename Type, size_t RowSize, size_t ColumnSize>
inline auto matrix_static<Type, RowSize, ColumnSize>::set(size_type row, size_type col) -> reference
{
  return const_cast<reference>(static_cast<matrix_type const &>(*this).get(row, col));
}

template <typename Type, size_t RowSize, size_t ColumnSize>
inline auto matrix_static<Type, RowSize, ColumnSize>::add(matrix_type const&) noexcept -> matrix_type&
{
  return *this;
}

template <typename Type, size_t RowSize, size_t ColumnSize>
inline auto matrix_static<Type, RowSize, ColumnSize>::sub(matrix_type const&) noexcept -> matrix_type&
{
  return *this;
}



} // matrix
} // nimu