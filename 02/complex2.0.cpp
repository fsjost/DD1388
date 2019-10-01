#include <iostream>
#include <string>
#include <math.h>
#include <regex>
#include "complex2.0.h"

    Complex Complex::operator=(Complex other){                                 // Kan vara fel?
    this -> a = other.real();
    this -> b = other.imag();
    return other;
  }

  double Complex::real(){
    return this -> a;
  }
  double Complex::imag(){
    return this -> b;
  }

  Complex& Complex::operator+=(Complex other){
    this -> a += other.real();
    this -> b += other.imag();
    return *this;
    }

  Complex& Complex::operator+=(double other){
      this -> a += other;
      return *this;
      }

  Complex& Complex::operator-=(Complex other){
    this -> a -= other.real();
    this -> b -= other.imag();
    return *this;
    }

  Complex& Complex::operator-=(double other){
    this -> a -= other;
    return *this;
    }

  Complex& Complex::operator*=(Complex other){
    double atemp = this -> a;
    this -> a = atemp*other.real()-b*other.imag();
    this -> b = atemp*other.imag()+b*other.real();
    return *this;
    }

  Complex& Complex::operator*=(double other){
    this -> a = a*other;
    this -> b = b*other;
    return *this;
    }

  Complex& Complex::operator/=(Complex other){
      double atemp = this -> a;
      double btemp = this -> b;
      this -> a = (atemp*other.real()+btemp*other.imag())/(pow(other.real(),2)+pow(other.imag(),2));
      this -> b = (btemp*other.real()-atemp*other.imag())/(pow(other.real(),2)+pow(other.imag(),2));
      return *this;
      }

  Complex& Complex::operator/=(double other){
    this -> a /= other;
    this -> b /= other;
    return *this;
  }


  double real(Complex other){
      return other.real();
  }

  double imag(Complex other){
      return other.imag();
  }

  double abs(Complex other){
      return sqrt(pow(other.real(),2)+pow(other.imag(),2));
  }

  Complex operator+(Complex other, double a){
    return other += a;
  }

  Complex operator+(Complex other1, Complex other2){
      return other1 += other2;
  }

  Complex operator-(Complex other, double a){
      return other -= a;
  }

  Complex operator-(Complex other1,Complex other2){
      return other1 -= other2;
  }

  Complex operator*(Complex other,double a){
      return other *= a;
  }

  Complex operator*(Complex other1,Complex other2){
    return other1 *= other2;
  }

  Complex operator/(Complex other, double a){
    return other /= a;
  }

  Complex operator/(Complex other1,Complex other2){
    return other1 /= other2;
  }

  bool operator==(Complex other1, Complex other2){
    return (other1.real() == other2.real() && other1.imag()== other2.imag());
  }

  bool operator!=(Complex other1, Complex other2){
    return !(other1.real() == other2.real() && other1.imag()== other2.imag());
  }

constexpr Complex operator""_i(long double d) { return Complex(0.0, d); } //floating

constexpr Complex operator""_i(unsigned long long d) { return Complex(0.0, d); } //floating

  ostream &operator<<(ostream &os, Complex other){
    os << "("<<other.real() << "," << other.imag() << ")"<< endl;
    return os;
  }

  Complex &operator>>(istream &is, Complex &other){
    string s;
    is >> s;
    regex RealNumb("^\\d+\\.\\d+$|^\\d+$");
    regex RealParNumb("^\\(\\d+\\)$|^\\(\\d+\\.\\d+\\)$");
    regex ComplexNumb("^\\(\\d+\\.\\d+,\\d+\\.\\d+\\)$|^\\(\\d+\\.\\d+,\\d+\\)$|^\\(\\d+,\\d+\\.\\d+\\)$|^\\(\\d+,\\d+\\)$");
      if (regex_match(s, RealNumb)) {                         //Bara reell
        other = stod(s);
        return other;
      } else if(regex_match(s,RealParNumb)) {                //(Reel)
          s.erase(0,1); s.erase(end(s)-1, end(s));           // Delete first and last element (i.e., the parenthesis)
          other = stod(s);
          return other;
      } else if(regex_match(s,ComplexNumb)){                //(Helt tal) (Re,Im)
        string reString; string imString;
        s.erase(0,1); s.erase(end(s)-1, end(s));           // Delete first and last element (i.e., the parenthesis)
        reString = s; imString = s;
        reString.erase(reString.find(','),-1);
        imString.erase(0,imString.find(',')+1);
        other = Complex(stod(reString),stod(imString));
        return other;
      }
      else throw invalid_argument("This is not correct. SUMIMASEEEEEEN ;____________;");
    }

// Needs to be tagged out if cxxtest
/*
  int main(){
    Complex a = 4_i;
    a += 3;
    cout << imag(a);
    /*Complex d;
    cin >> d;
    cout << d;
    return 0;
}*/
