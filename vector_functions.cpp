#include "vector_functions.hpp"

#include <iterator>

using iterator = std::vector<int>::iterator; // just saves typing big thing over and over

// standard libraries included in header

std::vector<int> read_int_vector(){
  std::vector<int> int_vector;
  std::cout << "Input integers:\n";
  int user_input;
  while( 1 ){ // exit function once end of file encountered. Input Ctrl-Z is treated as end of file.
    // can do while( std::cin >> user_input ), but I prefer the style being used
    std::cout << "\t";
    std::cin >> user_input; // if input invalid, stream evaluates as false and bad data left in stream
    if( std::cin.eof() ){
      break;
    }
    else if( std::cin ){
      int_vector.push_back( user_input );
    }
    else if( !std::cin ){ // if invalid data entered and stream evaluates as false, clear error flags, remove bad data from stream, display error message
      std::cin.clear(); // stream can now evaluate as true
      std::string invalid_input;
      std::getline( std::cin, invalid_input ); // reads and removes invalid input from stream // using getline from string header, because >> only reads and removes until whitespace
      std::cout << "Invalid Input:\t" << invalid_input << "\n";
    }
  }
  std::cout << "End of file encountered.\n";

  return int_vector;

}

int sum( std::vector<int> int_vector ){ // for loop adding all vector elements togeather.
  int sum = 0; // += elements to this
  if( int_vector.empty() ){
    // sum doesn't change
  }
  else if( !int_vector.empty() ){
    for( int element : int_vector ){ // instead of the for( initialisation; condition; step ){} loop, where I'd use int_vector.size() to find out how many loops need to happen
      sum += element;
    }
  }
  return sum;
}

int int_average( std::vector<int> int_vector ){ // divide sum of vector elements by the size
  if( int_vector.empty() ){
    return 0;
  }
  else if( !int_vector.empty() ){ // could just use else{}, but I want to practice using the inversion operator
    return sum( int_vector ) / int_vector.size();
  }          // Integer data type arithmetic, so it's sum DIV size, not divide.
}
float float_average( std::vector<int> int_vector ){
  if( int_vector.empty() ){
    return 0;
  }
  else if( !int_vector.empty() ){
    return float( sum( int_vector ) ) / float( int_vector.size() );
  }
}

std::vector<int> filter_greater_than( std::vector<int> int_vector, int filter){

  std::vector<int> filtered_int_vector;
  for( int8_t vector_index = 0; vector_index < int_vector.size(); ++ vector_index ){ // instead of for( auto element : vector ){}
    int current_element = int_vector[ vector_index ];
    if( current_element > filter ){
        filtered_int_vector.push_back( current_element );
    }
  }
  return filtered_int_vector;
}

void testing_vector_iterator( std::vector<int> my_int_vector ){
  std::cout << "Experimenting with vector iterators:\n";

  auto iterator_1 = my_int_vector.begin();
  std::vector<int>::iterator iterator_2 = iterator_1 + 1; // seems auto does become std::vector<int>::iterator
  auto iterator_3 = my_int_vector.end();
  std::vector<int>::iterator iterator_4 = iterator_3 -1; // to reference final index element

  std::cout << "\t*std::vector<int>.begin():\t" << *iterator_1 << "\n" ; // dereference iterator to get vector index element being referenced
  std::cout << "\t*std::vector<int>.begin() + 1:\t" << *iterator_2 << "\n";
  std::cout << "\t*std::vector<int>.end():\t" << *iterator_3 << "\n";
  std::cout << "\t*std::vector<int>.end() - 1:\t" << *iterator_4 << "\n\n";
  return;
}

///////////////////////////////////////////////
////////////////// SORTING ////////////////////
///////////////////////////////////////////////
std::vector<int> sort( std::vector<int> int_vector ){
  // declaring functions here, which are defined later, so they can be referenced before their definitions made
  std::vector<int>::iterator partition( iterator begin, iterator end ); // these declarations only in this function's scope
  // using iterator = std::vector<int>::iterator; <- saves having to keep typing std::vector<int>::iterator
  void sort_impl( iterator begin, iterator end );

  sort_impl( int_vector.begin(), int_vector.end() );
  return int_vector;
}
void sort_impl( iterator begin, iterator end ){
  iterator partition( iterator begin, iterator end ); // redeclaration. function not defined yet, and previous declaration out of scope
  // if the vector contains 1 thing, no sorting needed
  if( (end-begin) <= 1 ){
    return; // exits function
  }
  // use partition to get ranges within a vector. // 1st range is iterator vector.begin-iterator pivot. // 2nd range is pivot+1-end
  std::vector<int>::iterator pivot = partition( begin, end ); // iterator or auto as the type, would work instead of std::vector<int>::iterator
  sort_impl( begin, pivot ); // Recursion. Function calling itself.
  sort_impl( pivot+1, end );
}
iterator partition( iterator begin, iterator end ){
  iterator pivot = begin ++; // post increment. variable assigned old value of parameter.
  // for( initialisation; condition; step ), but ommitting initialisation
  for( ; begin != end; ++ begin ){ // *dereference iterators to get vector element being referenced
    if( *pivot > *begin ){ // Have to move elements < *pivot to the left of *pivot // use std::swap to swap elements between 2 vector indexes
      std::swap( *pivot, *begin );
      ++pivot; // now swap again so the pivot iterator references its original element
      std::swap( *pivot, *begin );
    }
  }
  return pivot; // all elements to the left are smaller. Elements to the right are bigger.
}




