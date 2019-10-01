#ifndef complex_class_H_
#define complex_class_H_

using namespace std;


class Complex{
private:
  double a;
  double b;

public:
  constexpr Complex(double a = 0, double b = 0): a(a), b(b){};

  Complex operator=(Complex other);

  double real();
  double imag();

  Complex& operator+=(Complex other);

  Complex& operator+=(double other);

  Complex& operator-=(Complex other);

  Complex& operator-=(double other);

  Complex& operator*=(Complex other);

  Complex& operator*=(double other);

  Complex& operator/=(Complex other);

  Complex& operator/=(double other);
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
constexpr Complex operator""_i(long double a);
constexpr Complex operator""_i(unsigned long long a);


// OUTSTREAM AND INSTREAM
ostream &operator<<(ostream &os, Complex other);
Complex &operator>>(istream &is, Complex &other);

#endif
