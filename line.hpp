#ifndef _LINE_HPP
#define _LINE_HPP

#include <iostream>
#include <string>
#include <vector>

struct line {
  std::string first;
  std::string second;
};

std::istream& read_lines(std::istream& in, std::vector<line>& lines);

#endif // _LINE_HPP