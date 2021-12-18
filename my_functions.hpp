#ifndef MY_FUNCTIONS
#define MY_FUNCTIONS // preprocessor directive create macros that are guarded. ?from being put into program text multiple times?

#include <iostream>
#include <vector>
#include <string>

std::vector<int> read_int_vector(); // function declaraion. Definitions are in the source file.
int sum( std::vector<int> int_vector );
int int_average( std::vector<int> int_vector );
float float_average( std::vector<int> int_vector );
std::vector<int> filter_greater_than( std::vector<int> int_vector, int filter );

#endif
