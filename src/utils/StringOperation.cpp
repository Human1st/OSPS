#include <sstream>

#include "StringOperation.hpp"

std::vector<std::string> StringOperation::split(std::string text, char delim) {
    std::string line;
    std::vector<std::string> vec;
    std::stringstream ss(text);
    while(std::getline(ss, line, delim)) {
        vec.push_back(line);
    }
    return vec;
}
