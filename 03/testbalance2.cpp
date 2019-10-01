#include "bintree.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <random>
#include <algorithm>

  std::vector<double> create_vector(int size){
    unsigned birthSeed = (950505);
    std::vector<double> arr(size);
    for(int i = 0; i < size; ++i){
        arr[i] = i+1;
      }
      shuffle(std::begin(arr),std::end(arr),std::default_random_engine(birthSeed));
      return arr;
    }

  int main() {
    std::vector<double> arr = create_vector(9000);                                                                       // creates vector to save in (800)
    Node * p = nullptr;
    double maxDiff = 0;      double maxHeight = 0;
    double minDiff = 9000;   double minHeight = 9000;
    double avgMinMax = 0;    double avgMinHeight = 0;
    double diff = 0;         double avgMax = 0;
    for(int k = 0; k<800; k++){
      std::next_permutation(arr.begin(),arr.end());
        for(int  i = 8999;i >= 0;i--){
          insert(p, arr[i],arr[i]);
        }
        diff = max_height(p)-min_height(p);
        if(diff > maxDiff)
          maxDiff = diff;
        if(max_height(p) > maxHeight)
          maxHeight = max_height(p);
        if(diff < minDiff)
          minDiff= diff;
        if(min_height(p) < minHeight)
          minHeight = min_height(p);
        avgMax = avgMax +max_height(p);
        avgMinMax = avgMinMax + diff;
        avgMinHeight = avgMinHeight + min_height(p);
        delete_tree(p);
    }
    std::cout << "\nThe average height of the tree in 800 iterations: " << std::setprecision (4) << avgMax/800<< std::endl;
    std::cout << "Highest maximum height: " << maxHeight << std::endl;
    std::cout << "Average minimum height: " << std::setprecision (3) << avgMinHeight/800 << std::endl;
    std::cout << "Average difference between minimum and maximum height: " << std::setprecision (4) << avgMinMax/800 << std::endl;
    std::cout << "Lowest minimum height: " << minHeight << std::endl;
    std::cout << "The greatest difference between between minimum and maximum height: " << maxDiff << std::endl;
    std::cout << "The lowest difference between minimum and maximum height: " <<  minDiff << std::endl;
    return 0;
  }
