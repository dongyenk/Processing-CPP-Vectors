#include "my_functions.hpp"

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

std::vector<int> filter_greater_than( std::vector<int> int_vector, int filter ){
  std::vector<int> filtered_int_vector;
  for( int8_t vector_index = 0; vector_index < int_vector.size(); ++ vector_index ){ // instead of for( auto element : vector ){}
    int current_element = int_vector[ vector_index ];
    if( current_element > filter ){
        filtered_int_vector.push_back( current_element );
    }
  }
  return filtered_int_vector;
}




