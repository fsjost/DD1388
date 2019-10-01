#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <string>
#include <unordered_map>
#include "watermanager.h"
#include <random>



class Gnu{
  public:
    int id;
    Gnu(int id){
      id = id;
    };
    void Gnu::operator()(){
      int drink;
      int sleep;
      sleep = randomInt(4, 6);
      drink = randomInt(0, 3);
       std::this_thread::sleep_for(std::chrono::seconds(sleep));
       watermanager.gnuEnters();
       std::this_thread::sleep_for(std::chrono::seconds(drink));
       watermanager.gnuLeaves();
     };
  };


  ostream & std::operator<<(ostream & os, const Gnu & g) {
    os << "Gnu nr: "<< g.id() << std::endl;
    return os;
  };


  bool output = false;
  WaterManager watermanager;
  std::unordered_map<std::thread::id, std::string> trace;

  int randomInt(int min, int max) {
  	std::random_device rd;
  	std::mt19937 rng(rd());
  	std::uniform_int_distribution<int> uni(min, max);
  	return uni(rng);
  }

  void WaterManager::gnuEnters(){;
    std::unique_lock<std::mutex> lock(mtx);
    cond.wait(lock, [this] {return hyenasInside == 0;});
    gnusInside += 1;
    if(output) std::cout << trace[std::this_thread::get_id()]<< " enters the waterhole." <<"  nr gnu: "<< gnusInside <<"   nr hyenas: " << hyenasInside <<std::endl;
  }

  void WaterManager::gnuLeaves(){
    mtx.lock();
    gnusInside -=1;
    if(output) std::cout << trace[std::this_thread::get_id()]<< " leaves the waterhole." <<"  nr gnu: "<< gnusInside <<"   nr hyenas: " << hyenasInside <<std::endl;
    cond.notify_all();
    mtx.unlock();
    }


  void WaterManager::hyenaEnters(){
    std::unique_lock<std::mutex> lock(mtx);
    cond.wait(lock, [this] {return gnusInside == 0;});
    hyenasInside += 1;
    if(output) std::cout << trace[std::this_thread::get_id()]<< " enters the waterhole." <<"  nr gnu: "<< gnusInside <<"   nr hyenas: " << hyenasInside <<std::endl;
    }


  void WaterManager::hyenaLeaves(){
    mtx.lock();
    hyenasInside -= 1;
    if(output) std::cout << trace[std::this_thread::get_id()]<< " leaves the waterhole." <<"  nr gnu: "<< gnusInside <<"   nr hyenas: " << hyenasInside <<std::endl;
    cond.notify_all();
    mtx.unlock();
  }

  void hyena(){
    int drink;
    int sleep;
    sleep = randomInt(4, 6);
    drink = randomInt(0, 3);
    std::this_thread::sleep_for(std::chrono::seconds(sleep));
    if(output) std::cout << trace[std::this_thread::get_id()]<< " is thirsty" << std::endl;
  	watermanager.hyenaEnters();
    std::this_thread::sleep_for(std::chrono::seconds(drink));
  	watermanager.hyenaLeaves();
    }


int main(int argc, char const *argv[]) {
  int nrGnus = 2;
  int nrHyenas = 2;
  std::vector<std::thread> threadvec;
  for (int i = 0; i < nrGnus; i++){
    Gnu g = Gnu(i);
    std::function<void(void)> threadjob = g;
    threadvec.push_back(thread(threadjob));
    if(output) trace[threadvec.back().get_id()]  = "Gnu nr "+std::to_string(i+1);
  }
  for (int i = 0; i < nrHyenas; i++){
    threadvec.push_back(std::thread(hyena));
    if(output) trace[threadvec.back().get_id()]  = "Hyena nr "+std::to_string(i+1);
  }
  for (int i = 0; i < nrGnus+nrHyenas; i++)
    threadvec[i].join();
  return 0;
}
