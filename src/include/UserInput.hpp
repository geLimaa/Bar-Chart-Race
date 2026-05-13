#ifndef USER_INPUT_HPP
#define USER_INPUT_HPP
#include <string>

struct Config{
    int max_bars = 5;
    int fps = 24;
    std::string filename;
};

class UserInput {
  public:
    Config parse(int argc, char* argv[]);
};

#endif
