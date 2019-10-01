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

  Node*  make_Tree(Node * & p, std::vector<double> arr){
    for(size_t i = 0; i < arr.back(); ++i)
        insert(p, arr[i],arr[i]);
        return p;
  }

  Node* iterateTrees(Node * & p,  std::vector<double> arr, std::vector<double> &saveArrMax,std::vector<double> &saveArrMin){
    size_t i =0;
    do{
        make_Tree(p,arr);
        saveArrMax[i] = max_height(p);
        saveArrMin[i] = min_height(p);
        i = i+1;
        delete_tree(p);
      } while(std::next_permutation(arr.begin(),arr.end()) && i < saveArrMax.size());
    return p;
  }

  double calculateAverage(std::vector<double> saveArr){
        double sum;
        for(std::size_t i = 0; i < saveArr.size(); i++)
           sum += saveArr[i];
        return sum/saveArr.size();
    }

  double calculateDifference(std::vector<double> saveArrMin, std::vector<double> saveArrMax, std::vector<double> saveArrDiff){
      for(std::size_t i = 0;i<saveArrMin.size();i++){
        saveArrDiff[i] = saveArrMax[i]-saveArrMin[i];
      }
      return calculateAverage(saveArrDiff);
    }

  int CalcMaxDiff(std::vector<double> saveArrMin, std::vector<double> saveArrMax){
    int integer = 0;
    int diff = 0;
    for(std::size_t i = 0; i < saveArrMin.size(); i++){
        diff = saveArrMax[i]-saveArrMin[i];
        if(diff > integer){
          integer = diff;
        }
    }
    return integer;
  }

  int CalcMinDiff(std::vector<double> saveArrMin, std::vector<double> saveArrMax){
    int integer = 900;
    int diff = 0;
    for(std::size_t i = 0; i < saveArrMin.size(); i++){
        diff = saveArrMax[i]-saveArrMin[i];
        if(diff < integer){
          integer = diff;
        }
    }
    return integer;
  }
  void printFunction(std::vector<double> saveArrMin,std::vector<double> saveArrMax,std::vector<double> saveArrDiff){
      std::cout << "\nThe average height of the tree in 800 iterations: " << std::setprecision (3) <<calculateAverage(saveArrMax) << std::endl;
      std::cout << "Highest maximum height: " << *std::max_element(saveArrMax.begin(),saveArrMax.end()) << std::endl;
      std::cout << "Average minimum height: " << std::setprecision (3) << calculateAverage(saveArrMin) << std::endl;
      std::cout << "Average difference between minimum and maximum height: " << std::setprecision(3) << calculateDifference(saveArrMin,saveArrMax,saveArrDiff) << std::endl;
      std::cout << "Lowest minimum height: " << *std::min_element(saveArrMin.begin(),saveArrMin.end()) << std::endl;
      std::cout << "The greatest difference between between minimum and maximum height: " << CalcMaxDiff(saveArrMin, saveArrMax) << std::endl;
      std::cout << "The lowest difference between minimum and maximum height: " << CalcMinDiff(saveArrMin, saveArrMax) << std::endl;
    }

  int main() {
    std::vector<double> arr = create_vector(5);                                          //creates the desired array (9000)
    std::vector<double> saveArrMax = create_vector(2);                                       // creates vector to save in (800)
    std::vector<double> saveArrMin = create_vector(2);                                       // creates vector to save in (800)
    std::vector<double> saveArrDiff = create_vector(2);                                       // creates vector to save in (800)
    //std::cout << saveArr[1] << std::endl;         // first: 8
    Node * root = nullptr;
    iterateTrees(root,arr,saveArrMax,saveArrMin);
    printFunction(saveArrMin,saveArrMax,saveArrDiff);
    delete_tree(root);
    return 0;
  }
