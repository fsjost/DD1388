#include "matrix.h"
#include <iostream>
#include <cmath>


template <class T>
Matrix<T>::Matrix(unsigned int n){
  static_assert(std::is_copy_constructible<T>::value && std::is_move_assignable<T>::value, "Please be reasonable.");
  set_m_rows(n);
  set_m_cols(n);
  set_m_capacity(n);
  this -> m_vec = new T [n*n];
  for(unsigned int i = 0;i< n;i++){
    for(unsigned int j = 0;j <n;j++){
      this ->m_vec[i*n+j] = 0;
    }
  }
}

template <class T>
Matrix<T>::Matrix(unsigned int n, unsigned int m){
  static_assert(std::is_copy_constructible<T>::value && std::is_move_assignable<T>::value, "Please be reasonable.");
  set_m_rows(n);
  set_m_cols(m);
  set_m_capacity(n);
  this -> m_vec = new T [n*m];
  for(unsigned int i = 0;i< n;i++){
    for(unsigned int j = 0;j <m;j++){
      this ->m_vec[i*m+j] = 0;
    }
  }
}

template  <class T>
Matrix<T>::Matrix(){
  this -> m_rows = 1; this -> m_cols = 1; this -> m_capacity = 1;
  this -> m_vec = new T[1];
}

template  <class T>
Matrix<T>::Matrix(const T n){
  this -> m_rows = 1; this -> m_cols = 1; this -> m_capacity = 1;
  this -> m_vec = new T[1];
}

template <class T>
Matrix<T>::Matrix(Matrix &obj){
  size_t rows = obj.get_m_rows();
  size_t cols = obj.get_m_cols();
  this -> m_rows = rows;
  this -> m_cols = cols;
  this -> m_vec = new T [rows*cols];
  this -> m_capacity = rows*cols;
  for(size_t i = 0;i < rows;i++){
    for(size_t j = 0;j < cols;j++){
      this -> m_vec[i*cols+j] = obj(i,j);
    }
  }
}

template  <class T>
Matrix<T>::~Matrix(){
  delete [] m_vec;
}

template <class T>
Matrix<T>::Matrix(Matrix &&obj){
  size_t rows = obj.get_m_rows();
  size_t cols = obj.get_m_cols();
  this -> m_rows = rows;
  this -> m_cols = cols;
  this -> m_vec = new T [rows*cols];
  this -> m_capacity = rows*cols;
  m_vec = nullptr;
}

template <class T>
Matrix<T>& Matrix<T>::operator=(Matrix &&obj){
  if (this !=&obj)
  {
    delete [] m_vec;
    obj.m_rows = 0;
    obj.m_cols = 0;
    obj.m_capacity = 0;
    obj.m_vec = nullptr;
  }
  return *this;
  }

template <class T>
void Matrix<T>::operator+=(Matrix &obj){
  if(this -> m_capacity != obj.get_m_capacity())
    throw std::out_of_range("Invalid input. Please try again.");
  for(unsigned int i = 0;i < obj.get_m_rows();i++){
    for(unsigned int j = 0;j < obj.get_m_cols();j++){
      this -> m_vec[i+m_cols*j] += obj(i,j);
      }
    }
  }

template <class T>
void Matrix<T>::operator+=(const T number){
  for(unsigned int i = 0;i < this -> m_rows;i++){
    for(unsigned int j = 0;j < this -> m_cols;j++){
      this -> m_vec[i+m_cols*j] += number;
      }
    }
  }

  template <class T>
  void Matrix<T>::operator-=(const T number){
    for(unsigned int i = 0;i < this -> m_rows;i++){
      for(unsigned int j = 0;j < this -> m_cols;j++){
        this -> m_vec[i+m_cols*j] -= number;
        }
      }
    }

    template <class T>
    void Matrix<T>::operator-=(Matrix &obj){
      if(this -> m_capacity != obj.get_m_capacity())
        throw std::out_of_range("Invalid input. Please try again.");
      for(unsigned int i = 0;i < obj.get_m_rows();i++){
        for(unsigned int j = 0;j < obj.get_m_cols();j++){
          this -> m_vec[i+m_cols*j] -= obj(i,j);
          }
        }
      }

    template <class T>
    void Matrix<T>::operator*=(const T number){
      for(unsigned int i = 0;i < this -> m_rows;i++){
        for(unsigned int j = 0;j < this -> m_cols;j++){
          this -> m_vec[i+m_cols*j] *= number;
          }
        }
      }

      template <class T>
      void Matrix<T>::operator*=(Matrix &obj){
        if(this -> m_capacity != obj.get_m_capacity())
          throw std::out_of_range("Invalid input. Please try again.");
        for(unsigned int i = 0;i < obj.get_m_rows();i++){
          for(unsigned int j = 0;j < obj.get_m_cols();j++){
            this -> m_vec[i+m_cols*j] *= obj(i,j);
            }
          }
        }

  template <class T>
  void Matrix<T>::reset(){
    for(unsigned int i = 0;i< m_capacity;i++){
        m_vec[i] = T();
    }
  }


template <class T>
Matrix<T>::Matrix(std::initializer_list<T> l) :
  m_rows(sqrt(l.size())),
  m_cols(sqrt(l.size())),
  m_capacity(l.size())
  {
    if(fmod(sqrt(l.size()), 1) > 0)
      throw std::out_of_range("Invalid input. Please try again."); // GER LEAK OM THROW
    this -> m_vec = new T [m_capacity];
    for(unsigned int i = 0;i< m_capacity;i++){
        this ->m_vec[i] = l.begin()[i];
    }
  }

template <class T>
T & Matrix<T>::operator()(unsigned int row, unsigned int col){
    if(row > this -> m_rows-1 || col > this -> m_cols-1){
      throw std::out_of_range("The element you're searching for does not exist.");
    }
    //std::cout << "row " << row << "... cols " << this -> m_cols <<std::endl;
  return this -> m_vec[row*get_m_cols() + col];
}

template <class T>
void Matrix<T>::operator=(Matrix & obj){
  T*temp = new T[obj.m_capacity];
  for(unsigned int  j = 0; j < obj.m_capacity; j++){
    temp[j] = obj.m_vec[j];
  }
  delete[] this -> m_vec;
  size_t rows = obj.get_m_rows();
  size_t cols = obj.get_m_cols();
  this -> m_rows = rows;
  this -> m_cols = cols;
  this -> m_vec = new T [rows*cols];
  this -> m_capacity = rows*cols;
  for(size_t i = 0;i < rows;i++){
    for(size_t j = 0;j < cols;j++){
      this -> m_vec[i*cols+j] = temp[i*cols +j];
    }
  }
  delete [] temp;
}

template <class T>
void Matrix<T>::set_m_rows(T rows){
  this -> m_rows = rows;
}

template <class T>
void Matrix<T>::set_m_capacity(T n){
  this -> m_capacity = n*n;
}

template <class T>
void Matrix<T>::set_m_capacity(T n, T m){
  this -> m_capacity = n*m;
}

template <class T>
size_t Matrix<T>::get_m_rows(){
  return this -> m_rows;
}

template <class T>
size_t Matrix<T>::get_m_cols(){
  return this -> m_cols;
}

template <class T>
void Matrix<T>::set_m_cols(T cols){
  this -> m_cols = cols;
}

template <class T>
size_t Matrix<T>::get_m_capacity(){
  return this -> m_capacity;
}

template <class T>
Matrix<T> operator+(Matrix<T> &frst, Matrix<T> &scnd){
  if(frst.get_m_capacity() != scnd.get_m_capacity())       // skriv om
    throw std::out_of_range("Invalid input. Please try again.");
  Matrix<T> outvalue(frst.get_m_rows(),frst.get_m_cols());
  for(unsigned int i = 0;i< frst.get_m_rows();i++){
    for(unsigned int j = 0;j<frst.get_m_cols();j++){
      outvalue(i,j) = frst(i,j)+scnd(i,j);
    }
  }
  return outvalue;
}


template <class T>
Matrix<T> operator-(Matrix<T> &frst, Matrix<T> &scnd){
  if(frst.get_m_capacity() != scnd.get_m_capacity())       // skriv om
    throw std::out_of_range("Invalid input. Please try again.");
    Matrix<T> outvalue(frst.get_m_rows(),frst.get_m_cols());
  for(unsigned int i = 0;i< frst.get_m_rows();i++){
    for(unsigned int j = 0;j<frst.get_m_cols();j++){
      outvalue(i,j) = frst(i,j)-scnd(i,j);
    }
  }
  return outvalue;
}

template <class T>
Matrix<T> operator+(Matrix<T> &frst, T integer){
  Matrix<T> outvalue(frst.get_m_rows(),frst.get_m_cols());
  for(unsigned int i = 0;i< frst.get_m_rows();i++){
    for(unsigned int j = 0;j<frst.get_m_cols();j++){
      outvalue(i,j) = frst(i,j)+integer;
    }
  }
  return outvalue;
}

template <class T>
Matrix<T> operator-(Matrix<T> &frst, T integer){
  Matrix<T> outvalue(frst.get_m_rows(),frst.get_m_cols());
  for(unsigned int i = 0;i< frst.get_m_rows();i++){
    for(unsigned int j = 0;j<frst.get_m_cols();j++){
      outvalue(i,j) = frst(i,j)-integer;
    }
  }
  return outvalue;
}

template <class T>
Matrix<T> operator*(Matrix<T> &frst, Matrix<T> &scnd){
  if(frst.get_m_capacity() != scnd.get_m_capacity())       // skriv om
    throw std::out_of_range("Invalid input. Please try again.");
    Matrix<T> outvalue(frst.get_m_rows(),frst.get_m_cols());
  for(unsigned int i = 0;i< frst.get_m_rows();i++){
    for(unsigned int j = 0;j<frst.get_m_cols();j++){
      outvalue(i,j) = frst(i,j)*scnd(i,j);
    }
  }
  return outvalue;
}

template <class T>
Matrix<T> operator*(Matrix<T> &frst, T integer){
  Matrix<T> outvalue(frst.get_m_rows(),frst.get_m_cols());
  for(unsigned int i = 0;i< frst.get_m_rows();i++){
    for(unsigned int j = 0;j<frst.get_m_cols();j++){
      outvalue(i,j) = frst(i,j)*integer;
    }
  }
  return outvalue;
}


template <class T>
std::ostream &operator<<(std::ostream &os, Matrix<T> &obj){
  os << "Number of rows: " << obj.get_m_rows()<< std::endl;
  os << "Number of columns: " << obj.get_m_cols() <<"\n" <<std::endl;
  for(unsigned int i = 0;i< obj.get_m_rows();i++){
    for(unsigned int j = 0;j<obj.get_m_cols();j++){
      os << obj(i,j) << "\t";}
    os << std::endl;}
  return os;
}

template <class T>
Matrix<T> operator>>(std::istream &is, Matrix<T> &obj){
   int rows; int cols; int element;                              // lägg in en resize
   is >> rows >> cols;
   obj.set_m_rows(rows);
   obj.set_m_cols(cols);
   obj.set_m_capacity(rows*cols);
   //Matrix<T> obj(rows, cols);
   for(int i = 0;i< rows;i++){
     for(int j = 0;j< cols;j++){
       is >> element;
       obj(i,j) = element;
     }
   }
   return &obj;
 }

Matrix<int> identity(unsigned int n){
  Matrix<int> object(n);
  for(unsigned int i = 0;i< n;i++)
      object(i,i) = 1;
  return object;
}


template <class T>
void Matrix<T>::insert_row(unsigned int r){
  if(r>=get_m_rows()){
    throw std::out_of_range("You can only insert a row under a row that's in your matrix.");
  }
  T * temp = new T[m_capacity];
  for(unsigned int  j = 0; j < m_capacity; j++){
    temp[j] = m_vec[j];
  }
  delete [] m_vec;
  m_vec = new T[(get_m_rows()+1)*get_m_cols()];
  for(unsigned int i = 0;i<r; i++){
    for(unsigned int j = 0;j<get_m_cols(); j++){
      m_vec[i*get_m_cols() +j] = temp[i*get_m_cols() +j];
     }
  }
  for(unsigned int i = 0; i < get_m_cols();i++){
    m_vec[get_m_cols()*r+i] = 0;
    }
  for(unsigned int i = r+1; i < get_m_rows()+1;i++){
    for(unsigned int j =0; j < get_m_cols();j++){
    m_vec[i*get_m_cols()+j] = temp[(i-1)*get_m_cols()+j];
    }
  }
  m_rows++;
  delete [] temp;
}

template <class T>
void Matrix<T>::append_row(unsigned int r){
  if(r>get_m_rows()){
    throw std::out_of_range("You can only insert a row under a row that's in your matrix.");
  }
  T * temp = new T[m_capacity];
  for(unsigned int  j = 0; j < m_capacity; j++){
    temp[j] = m_vec[j];
  }
  delete [] m_vec;
  m_vec = new T[(get_m_rows()+1)*get_m_cols()];
  for(unsigned int i = 0;i<=r; i++){
    for(unsigned int j = 0;j<get_m_cols(); j++){
      m_vec[i*get_m_cols() +j] = temp[i*get_m_cols() +j];
     }
  }
  for(unsigned int i = 0; i < get_m_cols();i++){
    m_vec[get_m_cols()*(r+1)+i] = 0;
    }
  for(unsigned int i = r+2; i < get_m_rows()+1;i++){
    for(unsigned int j =0; j < get_m_cols();j++){
    m_vec[i*get_m_cols()+j] = temp[(i-1)*get_m_cols()+j];
    }
  }
  m_rows++;
  delete [] temp;
}

template <class T>
void Matrix<T>::remove_row(unsigned int r){
  if(r>get_m_rows()){
    throw std::out_of_range("You can only insert a row under a row that's in your matrix.");
  }
  T * temp = new T[m_capacity];
  for(unsigned int  j = 0; j < m_capacity; j++){
    temp[j] = m_vec[j];
  }
  delete [] m_vec;
  m_vec = new T[(get_m_rows()-1)*get_m_cols()];
  for(unsigned int i = 0;i<r; i++){
    for(unsigned int j = 0;j<get_m_cols(); j++){
      m_vec[i*get_m_cols() +j] = temp[i*get_m_cols() +j];
     }
  }
  for(unsigned int i = r+1; i < get_m_rows();i++){
    for(unsigned int j =0; j < get_m_cols();j++){
    m_vec[(i-1)*get_m_cols()+j] = temp[i*get_m_cols()+j];
    }
  }
  m_rows--;
  delete [] temp;
}

template <class T>
void Matrix<T>::insert_column(unsigned int c){
  if(c>=get_m_cols()){
    throw std::out_of_range("You can only insert a column before a column that's in your matrix.");
  }
  T * temp = new T[m_capacity];
  for(unsigned int  j = 0; j < m_capacity; j++){
    temp[j] = m_vec[j];
  }
  delete [] m_vec;
  m_vec = new T[get_m_rows()*(get_m_cols()+1)];
  int k = 0;
	for (unsigned int i = 0; i < (get_m_rows()*(get_m_cols()+1)); i++) {
		if (i == (c + (m_cols+1)*(k))) {
      m_vec[i] = 0;
			k += 1;
		}
		else {
			m_vec[i] = temp[i-k];
		}
	}
  m_cols++;
  delete [] temp;
}

template <class T>
void Matrix<T>::append_column(unsigned int c){
  if(c>=get_m_cols()){
    throw std::out_of_range("You can only append a column after a column that's in your matrix.");
  }
  T * temp = new T[m_capacity];
  for(unsigned int  j = 0; j < m_capacity; j++){
    temp[j] = m_vec[j];
  }
  delete [] m_vec;
  m_vec = new T[get_m_rows()*(get_m_cols()+1)];
  int k = 0;
	for (unsigned int i = 0; i < (get_m_rows()*(get_m_cols()+1)); i++) {
		if (i == (c + (m_cols+1)*(k))+1) {
      m_vec[i] = 0;
			k += 1;
		}
		else {
			m_vec[i] = temp[i-k];
		}
	}
  m_cols++;
  delete [] temp;
}

template <class T>
void Matrix<T>::remove_column(unsigned int c){
  if(c>=get_m_cols()){
    throw std::out_of_range("You can only append a column after a column that's in your matrix.");
  }
  T * temp = new T[m_capacity];
  for(unsigned int  j = 0; j < m_capacity; j++){
    temp[j] = m_vec[j];
  }
  delete [] m_vec;
  m_vec = new T[get_m_rows()*(get_m_cols()-1)];
  int k = 0;
	for (unsigned int i = 0; i < (get_m_rows()*(get_m_cols()-1)); i++) {
		if (i == (c + (m_cols-1)*(k))) {
      m_vec[i] = temp[i+k+1];
			k += 1;
		}
		else {
			m_vec[i] = temp[i+k];
		}
	}
  m_cols--;
  delete [] temp;
}


template <class T>
T* Matrix<T>::begin() {
	T *begin = &(m_vec[0]);
	return begin;
}


template <class T>
T* Matrix<T>::end() {
	T *end = &(m_vec[m_capacity-1]);
	return end;
}

template <class T>
bool Matrix<T>::operator==(Matrix<T>& rhs) {
	if ((get_m_rows() == rhs.get_m_rows()) && (get_m_cols() == rhs.get_m_cols())) {
		for (unsigned int i; i = 0; i++) {
			if (m_vec[i] != rhs.m_vec[i]) {
				return false;
			}
		}
		return true;
	}
	else {
		return false;
	}
}


int main() {
  //Matrix<int> a = {1,2,3,4,5,6,7,8,9};
  //Matrix<int> b = {1,2,3,4};
  //std::cout << b << std::endl;
  //b.remove_column(0);
  //Matrix<int> c = identity(2);
  //std::cout << a <<std::endl;
  //std::cout << b << std::endl;
  Matrix<int> mat2 = { 1, 2, 3, 4 };
  Matrix<int> mat3 = { 1,2,3,4};
  //mat3.remove_row(1);
  //std::cout << mat3 << std::endl;
  //std::cin >> c;
  //std::cout << c;
  //reset(b);
  //Matrix<int> o = {9,8,7,6,5,4,3};
  // a *= 10;
  // Matrix<int> add = a - b;
  // std::cout << add(0,0)<<std::endl;
  //std::cout << a(0,0)<<std::endl;
  //add = a + o;
  return 0;
}
