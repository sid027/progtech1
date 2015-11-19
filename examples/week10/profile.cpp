#include <iostream>
#include <vector>

std::size_t insert_begin() 
{
  std::vector<int> v;
  for (int i=0;i<100000;++i)
    v.insert(v.begin(),1);
  return v.size();
}

std::size_t insert_end() 
{
  std::vector<int> v;
  for (int i=0;i<100000;++i)
    v.push_back(1);
  return v.size();
}

int main() 
{
  for (int i=0;i<50;++i) {
	std::cout << insert_begin();
	std::cout << insert_end();
  }
}
