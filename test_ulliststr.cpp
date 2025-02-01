#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr temp;
  // temp.push_back("orange");
  // temp.push_front("apple");
  // temp.push_back("pear");
  // std::cout << temp.get(0) << " " << temp.get(1) << " " << temp.get(2) << std::endl;
  // // prints: apple orange pear

  temp.pop_front();
  std::cout << temp.size() << std::endl;
  // prints 3 since there are 3 strings stored


}
