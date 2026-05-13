#ifndef READER_HPP
#define READER_HPP
#include "Database.hpp"
#include <string>

class Reader{
  public:
    Database readFile(std::string filename);
};

#endif
