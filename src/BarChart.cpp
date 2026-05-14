#include "include/BarChart.hpp"
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

BarChart::BarChart(std::vector<BarItem> b, std::string f) : bars(b) , frame(f) {
  std::vector<std::string> colors = {
    "\033[31m",
    "\033[32m",
    "\033[33m",
    "\033[34m",
    "\033[35m",
    "\033[36m",

    "\033[91m",
    "\033[92m",
    "\033[93m",
    "\033[94m",
    "\033[95m",
    "\033[96m",

    "\033[37m",
    "\033[90m"
  };

  int color_index = 0;

  for(auto bar : bars){
    if(color_map.find(bar.bar_category) == color_map.end()){
      color_map[bar.bar_category] = colors[color_index];
      color_index++;
      color_index %= colors.size();
    }
  }
}

void BarChart::addBar(BarItem bar){ bars.push_back(bar); }

void BarChart::sortBars(){
  std::sort(bars.begin(), bars.end(),[](const BarItem& a, const BarItem& b){
    return a.bar_value > b.bar_value;
  });
}

void BarChart::addColor(std::string category, std::string color){
  color_map[category] = color;
}

std::string BarChart::getColor(std::string category) const{
  auto it = color_map.find(category);

  if(it != color_map.end()){ return it-> second; }
  return "\033[37m";
}

const std::vector<BarItem>& BarChart::getBars() const{ return bars; }
const std::string& BarChart::getFrame() const{ return frame; }

