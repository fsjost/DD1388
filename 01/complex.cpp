#include <iostream>

class Complex {
public:
   Complex () {
     std::cout << "default-constructor" << std::endl;
   }

   Complex (Complex const& src) {
     std::cout << "copy-constructor" << std::endl;
   }

  ~Complex () {
    std::cout << "destructor" << std::endl;
  }

   Complex(char const* s) {
      std::cout << "some other constructor" << std::endl;
   }

   Complex& operator= (Complex const& src) {
     std::cout << "the assignment operator" << std::endl;
     return *this;
   }
};

void no_ref(Complex a) {}
void with_ref(const Complex & a) {}

int main()
{
    Complex a("3_2i");

    Complex b = a;          // what is the difference
    Complex c(a);           // between these three
    Complex d;              // forms of initialization?

    d = a;

    no_ref (a);       // will this copy the value of `a`?
    with_ref (a);     // will this copy the value of `a`?

    Complex *aa = new Complex[5];
    delete aa;        // what will happen?
    return 0;
}
