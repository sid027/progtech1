/* Programming Techniques for Scientific Simulations, HS 2015
 * Exercise 7.1
 */

#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
#include <iterator>
#include <utility>
#include <limits>

typedef unsigned long test_type;

template <class container>
void fill_container(const std::size_t num_ops, container& s) {
  typename container::iterator it;
  typename container::value_type pos;

  for(std::size_t o=0; o < num_ops; ++o) {
    pos=std::rand()%s.size();
    it=s.begin();
    std::advance(it,pos+1);
    it=s.insert(it,2*pos+1);
    s.erase(it);
  }
}

template <class T>
void fill_container(const std::size_t num_ops, std::set<T>& s) {
  for(std::size_t o=0; o < num_ops; ++o){
    std::pair<typename std::set<T>::iterator,bool> output_pair = s.insert(2*(std::rand()%s.size())+1);
    if(output_pair.second) s.erase(output_pair.first);
  }
}

int main()
{
  const std::size_t num_ops = 4e06;

  std::chrono::time_point< std::chrono::high_resolution_clock > start , stop;

  std::cout << "# N Vector[s] List[s] Set[s]" << std::endl;
  for(unsigned i = 4; i < 14; ++i){

    const std::size_t size = 1ul << i;

    test_type* array = new test_type[size];
    for(std::size_t i=0; i < size; ++i)
      array[i] = 2*i;

    std::cout << size << std::flush;

    //vector

    std::vector<test_type> vec_(array,array+size);

    start = std::chrono::high_resolution_clock::now();
    fill_container(num_ops,vec_);
    stop = std::chrono::high_resolution_clock::now();

    std::cout << ' ' << static_cast<std::chrono::duration<double> >(stop-start).count() << std::flush;

    //list

    std::list<test_type> list_(array,array+size);

    start = std::chrono::high_resolution_clock::now();
    fill_container(num_ops,list_);
    stop = std::chrono::high_resolution_clock::now();

    std::cout << ' ' << static_cast<std::chrono::duration<double> >(stop-start).count() << std::flush;

    // set

    std::set<test_type> set_(array,array+size);

    start = std::chrono::high_resolution_clock::now();
    fill_container(num_ops,set_);
    stop = std::chrono::high_resolution_clock::now();

    std::cout << ' ' << static_cast<std::chrono::duration<double> >(stop-start).count() << std::flush;

    //----

    std::cout << std::endl << std::flush;

    delete[] array;

  }

  return 0;
}
