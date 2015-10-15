#include "timer.hpp"
#include <chrono>

Timer::Timer() {
  tstart_ = std::chrono::high_resolution_clock::now();
}

void Timer::start() {
  tstart_ = std::chrono::high_resolution_clock::now();
}

void Timer::stop() {
  tend_ = std::chrono::high_resolution_clock::now();
}

double Timer::duration() const {
    
  return std::chrono::duration< double >(tend_ - tstart_).count();
}
