#include <mutex>
#include <condition_variable>
#include <atomic>

class WaterManager{
  public:
    std::atomic<int> hyenasInside = {0};
    std::atomic<int> gnusInside = {0};
    std::mutex mtx;
    std::condition_variable cond;
    void hyenaEnters();
    void gnuEnters();
    void hyenaLeaves();
    void gnuLeaves();
};
