#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

struct A {
    int data;
};

void foo(unique_ptr<A> p) {
  cout << p->data << endl;
}

void foo2(shared_ptr<A> p) {
  cout << p->data << endl;
}

struct BhasA;

struct AhasB {
    AhasB(shared_ptr<BhasA> b) : m_b(b)  {
        resource = new int[4];
    };

    weak_ptr<BhasA> m_b;
    int * resource;

    ~AhasB() {delete [] resource;}
    AhasB(const AhasB &) = delete;
    void operator=(const AhasB &) = delete;
};

struct BhasA {
    BhasA() {resource = new int[4];};

    shared_ptr<AhasB> m_a;
    int * resource;

    ~BhasA() {delete [] resource;}
    BhasA(const BhasA &) = delete;
    void operator=(const BhasA &) = delete;
};

struct B {
    B() { b = new int[4]; }

    int * b;
    ~B() { delete [] b; }
    B(const B &) = delete;
    void operator= (const B & ) = delete;
};

  int main(int argc, char const *argv[]) {
    //auto deleter = [&](B* n){ delete[] n ;};
    //unique_ptr<B, decltype(deleter)> pb2(new B[2], deleter);
    //function<void(B*)> fb =  [&](B* n){ delete[] n ;};
    unique_ptr<B, function<void(B*)> > pb1(new B[2],  [&](B* n){ delete[] n ;});
  return 0;
}



/*
Lambdas
int main(int argc, char const *argv[]) {
  //int extdata = 2;
  vector<int> v = {1, 3, 4, 5, 6, 7, 8, 9};
  //auto oddprint = [](int n){ if(n % 2 == 1) cout << n << endl;};
  //auto oddfkn2times = [](int& n){ if(n % 2 == 1) n = 2*n;};
  //auto addsize = [v](int& n){n = n+v.size();};
  //auto changedata =[& extdata](int & a, int  b){a = b;} ;
  //for_each(v.begin(), v.end(),addsize);
  //changedata(extdata,7);
  return 0;
}*/

/*
  //POINTERS
  int main(int argc, char const *argv[]){
  unique_ptr<A> pa(new A {4} );
  //cout << pa -> data;
  shared_ptr<A> sa(new A {5});
  cout << sa -> data;

  weak_ptr<A> wa = sa;
  cout << wa.lock()->data;
  cout << endl;
  return 0;

  unique_ptr<B> pb(new B[2]);

}
*/
