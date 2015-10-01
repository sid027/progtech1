#include <iostream>
#include <ctime> 
#include <chrono>

int main()
{
  std::cout << "Hello ETH students." << std::endl;
  
  std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
  std::time_t current_time = std::chrono::system_clock::to_time_t( now );

  std::cout << "It is now: " << std::ctime( &current_time ) << std::endl;

  return 0;
}
