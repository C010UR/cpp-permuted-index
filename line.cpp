#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#include "line.hpp"

using std::vector;
using std::string;
using std::istream;

/**
 * @brief Shifts first word of the second string to the first string.
 */
line shift(line ln) {
  ln.first = ln.first + " " + ln.second.substr(0, ln.second.find(' '));
  ln.second = ln.second.substr(ln.second.find(' ') + 1);
  return ln;
}

/**
 * @brief Converts a string to lower case.
 */
string tolower(string str) {
  for (string::iterator i = str.begin(); i < str.end(); i++) 
    *i = std::tolower(*i);
  return str;
}

/**
 * @brief Generates a set of shifts of the input string.
 */
vector<line> shift_lines(const string input) {
  // how many times to rotate
  unsigned counter = 0;
  for (string::size_type i = 0; i < input.length(); i++) {
    if (input[i] == ' ') counter++;
  }
  if (counter == 0) return vector<line>();

  // rotate counter times and push to the vector
  vector<line> res;
  res.push_back({"", input});
  for (unsigned i = 0; i < counter; i++)
    res.push_back(shift(*(res.end() - 1)));
  
  return res;
}

/**
 * @brief Compares the lowercase second strings of a line.
 */
bool compare_line(const line& x, const line& y) {
  string _x = tolower(x.second);
  string _y = tolower(y.second);
  return _x < _y;
}

/**
 * @brief Gets lines from the input stream IN and processes them to produce permuted index.
 * 
 * @param in input stream
 * @param lines processed input
 * @return istream& input stream with cleared errors
 */
istream& read_lines(istream& in, vector<line>& lines) {
  if (!in) return in;

  // clear any garbage in the vector
  lines.clear();

  vector<line> temp;
  string str;
  // process every line to the temp and then copy temp to the lines vector
  while (std::getline(in, str)) {
    temp.clear();
    temp = shift_lines(str);
    std::copy(temp.begin(), temp.end(), std::back_inserter(lines));
  }

  // sort the resulted vector to produce permuted index
  std::sort(lines.begin(), lines.end(), compare_line);

  // clear input errors
  in.clear();
  return in;
}