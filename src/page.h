#ifndef __PAGE_H__
#define __PAGE_H__

#include <string>
#include <vector>
#include "cv.h"
#include "highgui.h"
#include "question.h"

using namespace cv;

class Page {
 public:
  Page(std::vector<Question>, const Mat&, size, size, std::string);
  Page(std::vector<std::string>&, std::vector<point>, std::vector<point>, const Mat&, size, size, std::string);
  
  void read(void);
  std::vector<bool> answers(void);
  int numq(void) {return questions.size();}
  std::string filename(void);
  size getCalibrationSize();
  size getPageSize();
 private:
  std::string fname;
  std::vector<Question> questions;
  size calibrationRect;
  size page;
  Mat image;
};

#endif
