#include <iostream>
#include <cstdlib>
#include "hello.h"
#include <string.h>


void hello (const char * name, int count) {
  if ( count == 0)
    std::cout << "Hello!";
    else if(count == -1)
    std::cout << "ojoj!";
    else {
    std::cout << "Hello,";
      for(int i = 0; i < count; i++)
      std::cout <<" " << name;
      std::cout << "!\n";
  }
}


std::pair<const char *, int> parse_args (int argc, char * argv[]) {
  if(argc < 2)
      return std::make_pair("world",1);
    else if (argc == 2)
      return std::make_pair(argv[1], 1);
    else{
      if(std::atoi(argv[2]) == 0){
        if(strcmp(argv[2], "0") == 0)
            return std::make_pair(argv[1],-1);
          else if(std::atoi(argv[2]) > 0)
            return std::make_pair(argv[1],std::atoi(argv[2]));
          else{
            std::cerr << "error: 2nd argument must be an integral greater than zero!\n";
            return std::make_pair(argv[1],-1);
          }
        }
      else if(std::atoi(argv[2])<0){
        std::cerr << "error: 2nd argument must be an integral greater than zero!\n";
        return std::make_pair(argv[1],-1);
        }
      return std::make_pair(argv[1],std::atoi(argv[2]));
    }
}
