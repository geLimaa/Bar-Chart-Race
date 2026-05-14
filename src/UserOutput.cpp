#include "include/UserOutput.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

void UserOutput::drawChart(BarChart chart){
  std::cout << "\n" << chart.getFrame() << "\n\n";
  std::vector<BarItem> bars = chart.getBars();


  if(bars.empty()){ return; }
  int max_value = bars[0].bar_value;  // already sorted
  
  for(auto bar : bars){
    int width = (50 * bar.bar_value) / max_value; // preserve the proportion
    std::cout << std::setw(20) << std::left << bar.bar_name;
    
    for(int i = 0; i < width; i++){
      std::cout << chart.getColor(bar.bar_category) << "█";
    }

    std::cout << "\033[0m";

    std::cout << " " << bar.bar_value;
    std::cout << "\n";
  }
}

