#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>
    
class Timer {
public:
  Timer();
  void start();
  void stop();
  double duration() const;

private:
  using time_point_t = std::chrono::high_resolution_clock::time_point;
  time_point_t tstart_, tend_;
};

#endif // !defined TIMER_HPP
