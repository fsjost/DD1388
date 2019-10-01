/*#include <iostream>
#include <string>
#include <math.h>
#include <regex>
*/

#ifndef complex_class_H_
# define complex_class_H_

using namespace std;


class Complex{
private:
  double a;
  double b;

public:
    Complex(double a, double b){
    this -> a = a;
    this -> b = b;
  }

  Complex(double a){
    this -> a = a;
    this -> b = 0;
  }
  Complex(){
  this -> a = 0;
  this -> b = 0;
  }

  Complex operator=(Complex other){                                 // Kan vara fel?
    this -> a = other.real();
    this -> b = other.imag();
    return other;
  }

  double real(){
    return this -> a;
  }
  double imag(){
    return this -> b;
  }
  double abs(){
    return sqrt(pow(this ->a,2)+pow(this->b,2));
  }

  Complex& operator+=(Complex other){
    this -> a += other.real();
    this -> b += other.imag();
    return *this;
    }

  Complex& operator+=(float other){
      this -> a += other;
      return *this;
      }

  Complex& operator-=(Complex other){
    this -> a -= other.real();
    this -> b -= other.imag();
    return *this;
    }

  Complex& operator-=(float other){
    this -> a -= other;
    return *this;
    }

  Complex& operator*=(Complex other){
    double atemp = this -> a;
    this -> a = atemp*other.real()-b*other.imag();
    this -> b = atemp*other.imag()+b*other.real();
    return *this;
    }

  Complex& operator*=(float other){
    this -> a = a*other;
    this -> b = b*other;
    return *this;
    }

  Complex& operator/=(Complex other){
      double atemp = this -> a;
      double btemp = this -> b;
      this -> a = (atemp*other.real()+btemp*other.imag())/(pow(other.real(),2)+pow(other.imag(),2));
      this -> b = (btemp*other.real()-atemp*other.imag())/(pow(other.real(),2)+pow(other.imag(),2));
      return *this;
      }

  Complex& operator/=(float other){
    this -> a /= other;
    this -> b /= other;
    return *this;
  }

/*  void operator=(Complex& other){
    this -> a = other.real();
    this -> b = other.imag();
  } */
};

double real(Complex other);
double imag(Complex other);
double abs(Complex other);

// OPERATORS
Complex operator+(Complex other, double a);
Complex operator+(Complex other1, Complex other2);
Complex operator-(Complex other, double a);
Complex operator-(Complex other1,Complex other2);
Complex operator*(Complex other,double a);
Complex operator*(Complex other1,Complex other2);
Complex operator/(Complex other, double a);
Complex operator/(Complex other1,Complex other2);

bool operator==(Complex other1, Complex other2);
bool operator!=(Complex other1, Complex other2);
Complex operator""_i(long double a);

// OUTSTREAM AND INSTREAM
ostream &operator<<(ostream &os, Complex other);
Complex &operator>>(istream &is, Complex &other);

#endif
