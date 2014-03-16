#include <iostream>
#include <fstream>
#include <string>
#include <dirent.h>
#include <unistd.h>
#include "tournament.h"

int main(int argv, char** argc) {
  bool gotScansDir = false;
  int i = 1;
  bool gotPosFile = false;
  bool gotCalFile = false;
  bool gotDataDir = false;
  std::string posFile, calFile, scansDir, dataDir;
  while(i < argv-1) {
    if(argc[i][0] == '-') {
      if(argc[i][1] == 'p') {
	gotPosFile = true;
	posFile = std::string (argc[i+1]);
	i++;
      }
      else if(argc[i][1] == 'c') {
	gotCalFile = true;
	calFile = std::string (argc[i+1]);
	i++;
      }
      else if(argc[i][1] == 's') {
	gotScansDir = true;
	scansDir = std::string (argc[i+1]);
	i++;
      }
      else if(argc[i][1] == 'd') {
	gotDataDir = true;
	dataDir = std::string (argc[i+1]);
	i++;
      }
    }
    i++;
  }
  if(!gotScansDir) {
    std::cout << "Missing scans directory (-s)" << std::endl;
    return 1;
  }
  if(!gotPosFile) {
    std::cout << "Missing .pos file (-p)" << std::endl;
    return 1;
  }
  if(!gotCalFile) {
    std::cout << "Missing .cal file (-c)" << std::endl;
    return 1;
  }
  if(!gotDataDir) {
    std::cout << "Missing data directory (-d)" << std::endl;
    return 1;
  }
  Tournament t (scansDir);
  t.prepare(posFile, calFile);
  std::cout << "Prepared" << std::endl;
  t.process();
  std::cout << "Processed" << std::endl;
  t.report(dataDir);
  std::cout << "Reported" << std::endl;
  chdir(dataDir.c_str());
  std::system("python ../src/formatting/bintonum.py");
  std::cout << "Converted to csv" << std::endl;
  //std::system("python ./main.py");
  std::cout << "Ranked teams" << std::endl;
  return 0;
}