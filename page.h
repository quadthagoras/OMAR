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
  Page(std::vector<std::string>&, std::vector<point>, std::vector<point>, const Mat&);
  Page(std::vector<std::string>&, std::vector<point>, std::vector<point>, const Mat&, size, size);
  void read(void);
  std::vector<bool> answers(void);
  int numq(void) {return questions.size();}
 private:
  std::vector<Question> questions;
  size sp;
  size page;
  Mat image;
};

#endif
