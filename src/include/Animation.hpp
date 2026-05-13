#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include "Database.hpp"
#include "UserOutput.hpp"

class Animation{
  public:
    void play(Database db, int max_bars, int fps);
};

#endif
