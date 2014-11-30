#include "Util.hh"
#include <iostream>

std::vector<std::string> Util::split(const std::string &line, const std::string &delim) {
  size_t delimIndex = 0;
  size_t nextDelim = 0;
  std::vector<std::string> result;
  while ((nextDelim = line.find(delim, delimIndex)) != std::string::npos) {
    result.push_back(line.substr(delimIndex, nextDelim-delimIndex));
    delimIndex = nextDelim + 1;
  }
  result.push_back(line.substr(delimIndex, line.length()-delimIndex));
  return result;
}
