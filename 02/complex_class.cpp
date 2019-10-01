#include <iostream>
#include <string>
#include <math.h>
#include <regex>
#include "complex_class.h"

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
    other += a;
    return other;
  }

  Complex operator+(Complex other1, Complex other2){
    other1 += other2;
      return other1;
  }

  Complex operator-(Complex other, double a){
      other -= a;
      return other;
  }

  Complex operator-(Complex other1,Complex other2){
      other1 -= other2;
      return other1;
  }

  Complex operator*(Complex other,double a){
      other *= a;
      return other;
  }

  Complex operator*(Complex other1,Complex other2){
    other1 *= other2;
    return other1;
  }

  Complex operator/(Complex other, double a){
      other /= a;
      return other;
  }

  Complex operator/(Complex other1,Complex other2){
    other1 /= other2;
    return other1;
  }

  bool operator==(Complex other1, Complex other2){
    return (other1.real() == other2.real() && other1.imag()== other2.imag());
  }

  bool operator!=(Complex other1, Complex other2){
    return !(other1.real() == other2.real() && other1.imag()== other2.imag());
  }

  Complex operator""_i(long double a){
    return Complex(0,a);
  }

  Complex operator""_i(unsigned long long a){
    return Complex(0,a);
  }

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

int main(){
  Complex x; Complex y;
x = y + 1;
x = y + y + 1 + 5; // chaining
x = 2 + y;
x += y += 4; // chaining
  return 0;
}
