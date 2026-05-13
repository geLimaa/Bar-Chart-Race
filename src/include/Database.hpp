#ifndef DATABASE_HPP
#define DATABASE_HPP
#include "BarChart.hpp"
#include <string>
#include <vector>

class Database{
  private:
    std::vector<BarChart> charts;
  public:
    void addChart(BarChart chart);
    std::vector<BarChart> getCharts();
    BarChart getChart(int index);
    int size();
};

#endif
