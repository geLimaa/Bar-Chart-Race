#include "include/Reader.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

Database Reader::readFile(std::string filename){
  Database db;
  std::ifstream file(filename);
  
  if(!file.is_open()){
    std::cerr << "Error while opening the file :/" << std::endl;
    return db;
  }

  std::string line;
  for(int i = 0; i < 4; i++){
    std::getline(file, line);
  }

  while(std::getline(file, line)){
    if(line.empty()){ continue; }

    if(line.find(',') == std::string::npos){ // did not find , (it is the number of bars)
      int num_of_bars = std::stoi(line);

      std::vector<BarItem> bars;
      std::string frame;

      for(int i = 0; i < num_of_bars; i++){
        std::getline(file, line); // frame,name,info,value,category        
        std::stringstream ss(line);

        std::string field1;
        std::string field2;
        std::string field3;
        std::string field4;
        std::string field5;
        
        std::getline(ss, field1, ',');
        std::getline(ss, field2, ',');
        std::getline(ss, field3, ',');
        std::getline(ss, field4, ',');
        std::getline(ss, field5, ',');

        if(i == 0){ frame = field1; }
        int value = std::stoi(field4);
        BarItem item(field2, field5, value);

        bars.push_back(item);
      }
      BarChart chart(bars, frame);
      chart.sortBars();
      db.addChart(chart);
      }
    }
  return db;
}
