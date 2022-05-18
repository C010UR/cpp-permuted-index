#include <iostream>
#include <algorithm>

#include <string>
#include <vector>

#include "line.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(void) {

  vector<line> input;

  read_lines(cin, input);

  // find maximum size of the left side
  string::size_type max = 0;
  for (vector<line>::iterator i = input.begin(); i != input.end(); i++)
    if (i->first.length() > max) max = i->first.length();

  // print out the text
  cout << endl;
  for (vector<line>::iterator i = input.begin(); i != input.end(); i++) {
    cout << string(max - i->first.length(), ' ') << i->first << "  " << i->second << endl;
  }

  return EXIT_SUCCESS;
}