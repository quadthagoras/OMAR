/**
 * @file page.h
 * @brief An encapsulation of an image and its respective Question objects.
 */

#ifndef __PAGE_H__
#define __PAGE_H__

#include <string>
#include <vector>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "question.h"

using namespace cv;

/**
 * @class Page
 * @brief An encapsulation of an image and its metadata
 *
 * Each Page stores its image and information about its questions. It contains 
 * methods to read and return the answers.
 */

class Page {
 public:

  /**
   * Store the image and the metadata in member variables.
   *
   * @param qs A Question vector
   * @param src The source image
   * @param a The size of the calibration rectangle
   * @param b The size of the page
   * @param fn The name of the source file of the image
   */

  Page(std::vector<Question>, const Mat&, Size, Size, std::string);

  /**
   * Process the image by reading the mean value of each Question box and 
   * applying a threshold.
   */

  void read(void);

  /**
   * Get the data extracted from the image after a call to read().
   *
   * @return A vector of booleans representing the color of each Question box
   */

  std::vector<bool> answers(void);

  /**
   * Get the number of questions.
   *
   * @return The number of questions associated with the Page
   */

  int numq(void) {return questions.size();}

  /**
   * Get the name of the source file of the image.
   *
   * @return The name of the source file
   */

  std::string filename(void);

  /**
   * Get the size of the calibration rectangle.
   *
   * @return The size of the calibration rectangle
   */

  Size getCalibrationSize();

  /**
   * Get the size of the Page.
   *
   * @return The size of the Page
   */

  Size getPageSize();

 private:
  std::string fname;
  std::vector<Question> questions;
  Size calibrationRect;
  Size page;
  Mat image;
};

#endif
