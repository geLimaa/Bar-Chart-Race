#include "include/Database.hpp"
#include <vector>
#include <string>

void Database::addChart(BarChart chart){
  charts.push_back(chart);
}

std::vector<BarChart> Database::getCharts(){ return charts;}
BarChart Database::getChart(int index){ return charts[index]; }
int Database::size(){ return charts.size(); }
