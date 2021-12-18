#include "my_functions.hpp"

//#include <vector> // in header file

int main(){
  std::vector<int> my_int_vector = read_int_vector();
  std::cout << "Sum of elements:\t" << sum( my_int_vector ) << "\n";
  std::cout << "Integer average:\t" << int_average( my_int_vector ) << "\n";
  std::cout << "Float average:\t" << float_average( my_int_vector ) << "\n";
  int filter = 3; // with int8_t type, 3 becomes a heart
  std::cout << "Vector elements greater than " << filter << ".\n";
  for( auto element : filter_greater_than( my_int_vector, filter ) ){// function returns a vector, so can have code treating function like a vector
    std::cout << "\t" << element << "\n";  }
  return 0;
}
