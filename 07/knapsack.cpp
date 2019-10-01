#include <map>
#include <set>
#include <iostream>
#include <sstream>
std::map<int, int> weight_and_values = {
  {16, 24},
  {19, 29},
  {15, 23},
  {14, 22},
  {13, 21},
  {17, 28},
};


  void printout(){
    std::cout <<"\n" << "weight : values" << "\n";
    std::cout << "----------------"<< "\n";
    for(auto it = weight_and_values.rbegin(); it != weight_and_values.rend(); ++it){
      std::cout <<"  " << it -> first << "   : " <<  it -> second << "\n";
    }
    std::cout << "\n";
  }

template <typename S>
std::string greedytake(S start, S end, int N) {
   std::stringstream ss;
   std::stringstream weightstream;
   std::stringstream valuestream;
   int weight = 0;
   int value  = 0;
   int totalvalue = 0;
   int iterator;
   ss << "knacksacksize = " << N << " got value ";
   for(auto it = start; it != end; it++){
     iterator = 0;
     while(weight  + it -> first <= N){
        iterator ++;
        weight = weight + it -> first;
        value = value + it -> second;
     }  
     weightstream << iterator <<  " * " << it -> first;
     totalvalue += it-> second;
    }
    ss << value << " gold coins, and weight " << weight <<" ( " << weightstream.str() << " ) " <<"kg. "<< std::endl;
   return ss.str();
}

int main(int argc, char const *argv[]) {
  int N = 50;
  //printout();
  std::cout << greedytake(weight_and_values.rbegin(), weight_and_values.rend(), N) << std::endl;
  return 0;
}
