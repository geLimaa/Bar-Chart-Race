#include "include/BarChart.hpp"
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

BarChart::BarChart(std::vector<BarItem> b, std::string f) : bars(b) , frame(f) {
  std::vector<std::string> colors = {
    "\033[38;5;196m",
    "\033[38;5;202m",
    "\033[38;5;208m",
    "\033[38;5;214m",
    "\033[38;5;220m",

    "\033[38;5;160m",
    "\033[38;5;124m",
    "\033[38;5;88m",

    "\033[38;5;46m",
    "\033[38;5;82m",
    "\033[38;5;118m",

    "\033[38;5;21m",
    "\033[38;5;27m",
    "\033[38;5;33m",
    "\033[38;5;39m",

    "\033[38;5;93m",
    "\033[38;5;99m",
    "\033[38;5;105m",

    "\033[38;5;129m",
    "\033[38;5;135m",
    "\033[38;5;141m",

    "\033[38;5;226m",
    "\033[38;5;220m",
    "\033[38;5;226m",

    "\033[38;5;250m",
    "\033[38;5;245m",
    "\033[38;5;240m"
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

