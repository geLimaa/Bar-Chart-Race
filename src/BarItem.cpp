#include "include/BarItem.hpp"
#include <string>

BarItem::BarItem(const std::string& bn, const std::string& bc, int bv) : bar_name(bn) , bar_category(bc) , bar_value(bv) {}
bool BarItem::operator<(const BarItem& other){ return this->bar_value < other.bar_value; }
