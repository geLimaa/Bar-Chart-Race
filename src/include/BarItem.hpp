#ifndef BAR_ITEM_HPP
#define BAR_ITEM_HPP
#include <string>

struct BarItem {
  std::string bar_name;
  std::string bar_category;
  int bar_value;

  BarItem(const std::string& bn, const std::string& bc, int bv);
  bool operator<(const BarItem& other);
};

#endif
