#include "countWordsInString.h"

#include "duomenys.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include "countWordsInString.h"

int countWordsInString(std::string const& str)
{
    std::stringstream stream(str);
    return std::distance(std::istream_iterator<std::string>(stream), std::istream_iterator<std::string>());
}