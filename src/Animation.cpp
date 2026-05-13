#include "include/Animation.hpp"
#include <iostream>
#include <thread> // allows sleep_for
#include <chrono>
#include <cstdlib>  // allows system comands like clear

void Animation::play(Database db, int max_bars, int fps){
  UserOutput output;
  std::chrono::milliseconds duration(1000 / fps);

  for(int i = 0; i < db.size(); i++){
    BarChart chart = db.getChart(i);
    std::vector<BarItem> limited_bars;

    std::vector<BarItem> bars = chart.getBars();

    for(int j = 0; j < bars.size() && j < max_bars; j++){
      limited_bars.push_back(bars[j]);
    }

    BarChart limited_chart(limited_bars, chart.getFrame());
    output.drawChart(limited_chart);

    std::this_thread::sleep_for(duration);
    system("clear");
  }
}
