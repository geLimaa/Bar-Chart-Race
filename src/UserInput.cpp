#include "include/UserInput.hpp"
#include <iostream>
#include <string>

Config UserInput::parse(int argc, char* argv[]){
  Config config;
    
  if(argc < 2){ // No input file
    std::cout
      << "Usage: bcr [<options>] <input_data_file>\n"
      << "  Bar Chart Race options:\n"
      << "      -b <num> Max # of bars.\n"
      << "               Valid range is [1,15]. Default is 5.\n"
      << "      -f <num> Animation speed in fps.\n"
      << "               Valid range is [1,24]. Default is 24.\n";
    return config;
  }

  for(int i = 1; i < argc; i++){
    std::string arg = argv[i];

    // Max bars
    if(arg == "-b"){
      if(i + 1 < argc){
        config.max_bars =
        std::stoi(argv[++i]);

        // Validation
        if(config.max_bars < 1 || config.max_bars > 15){
          std::cerr << "Invalid bar amount.\n";
          config.max_bars = 5;
        }
      }
    }

    // FPS
    else if(arg == "-f"){
      if(i + 1 < argc){
        config.fps = std::stoi(argv[++i]);

        // Validation
        if(config.fps < 1 || config.fps > 24){
          std::cerr << "Invalid fps.\n";
          config.fps = 24;
        }
      }
    }
    // Filename
    else{
      config.filename = arg;
    }
  }
  return config;
}
