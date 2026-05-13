#ifndef BAR_CHART_HPP
#define BAR_CHART_HPP
#include "BarItem.hpp"
#include <unordered_map>
#include <string>
#include <vector>

class BarChart {
  private:
    std::vector<BarItem> bars;
    std::string frame;
    std::unordered_map<std::string, std::string> color_map;
    std::string default_color = "white";

  public:
    BarChart(std::vector<BarItem> b, std::string f);
    
    void addBar(BarItem bar);
    void sortBars();
    void addColor(std::string category, std::string color);
    
    std::string getColor(std::string category) const;
    const std::vector<BarItem>& getBars() const;
    const std::string& getFrame() const;
};

#endif
