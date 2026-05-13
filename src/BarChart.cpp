#include "include/BarChart.hpp"
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

BarChart::BarChart(std::vector<BarItem> b, std::string f) : bars(b) , frame(f) {}
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
  return default_color;
}

const std::vector<BarItem>& BarChart::getBars() const{ return bars; }
const std::string& BarChart::getFrame() const{ return frame; }

