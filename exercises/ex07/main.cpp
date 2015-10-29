#include <iostream>
#include "iterator.hpp"
#include "array.hpp"

int main()
{
	// Print numbers in normal order
	int nums[] = {1,2,3,4,5};
	for( unsigned i = 0 ; i < 5 ; ++i )
		std::cout << nums[i];
	std::cout << std::endl;

	Array<int> array( 5 );
	
	// Load numbers into array
	Array<int>::iterator iter = array.begin();
	for( unsigned i = 0  ; iter != array.end() ; ++i )
		*iter++ = nums[ i ];

	// Print numbers in reverse order
	iter = Iterator<int>( &array[ array.size() - 1 ] , &array[0] , &array[0] + array.size() );
	while( iter != array.begin() )
		std::cout << *iter--;
	std::cout << *iter << std::endl;

return 0;
}