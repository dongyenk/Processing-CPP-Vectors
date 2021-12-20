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
  void handle_iterator_range( iterator begin, iterator end );
  handle_iterator_range( int_vector.begin(), int_vector.end() ); // partition function does that actual re ordering
  return int_vector; // below functions order this
}
void handle_iterator_range( iterator begin, iterator end ){
  std::vector<int>::iterator partition( iterator begin, iterator end );

  if( end - begin <= 1 ){
    return;
  }
  else{
    auto pivot = partition( begin, end );
    handle_iterator_range( begin, pivot );
    handle_iterator_range( pivot+1, end ); // can increment an iterator, and it references the next index's element
  }
}
iterator partition( std::vector<int>::iterator begin, iterator end ){
  iterator pivot = begin ++; // post increment. pivot gets old begin value, while begin is incremented.
  for( ; begin != end; ++ begin ){ // ommitted initialisation
    if( *pivot > *begin ){
      std::swap( *pivot, *begin );
      ++ pivot; // now to swap again, to get original pivot element back
      std::swap( *pivot, *begin );
    }
  }
  return pivot;
}



