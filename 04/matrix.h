#ifndef _MATRIX_H_
#define _MATRIX_H_
#include <cstddef>
#include <initializer_list>

template <class T>
class Matrix {
public:
   // constructor
   Matrix(unsigned int n);
   Matrix(unsigned int n, unsigned int m);
   Matrix();
   Matrix(const T n);
   Matrix(Matrix &obj);
   ~Matrix();
   Matrix(Matrix &&obj);
   Matrix(std::initializer_list<T> l);

   // operators
   void operator=(Matrix & obj);
   T& operator()(unsigned int row, unsigned int col);
   Matrix& operator=( Matrix &&obj);
   void operator+=(Matrix &obj);
   void operator+=(const T number);
   void operator-=(const T number);
   void operator-=(Matrix &obj);
   void operator*=(const T number);
   void operator*=(Matrix &obj);
   bool operator==(Matrix & rhs);


   // methods
   void reset();
   void set_m_rows(T rows);
   void set_m_cols(T cols);
   void set_m_capacity(T n);
   void set_m_capacity(T n, T m);
   std::size_t get_m_rows();
   std::size_t get_m_cols();
   std::size_t get_m_capacity();
   void insert_row(unsigned int r);
   void append_row(unsigned int r);
   void remove_row(unsigned int r);
   void insert_column(unsigned int c);
   void append_column(unsigned int c);
   void remove_column(unsigned int c);
   T* begin();
   T* end();

private:
   std::size_t m_rows;
   std::size_t m_cols;
   std::size_t m_capacity;
   T * m_vec;
};

#endif
