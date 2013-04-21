#ifndef __ALIGN_H__
#define __ALIGN_H__

#include "cv.h"
#include "highgui.h"
#include <vector>

#define PI 3.141592653589793238462

using namespace cv;

void getCalibrationCircles(const Mat&, std::vector<Vec3f>&);
double getAngleOffset(std::vector<Vec3f>);
void rotateImage(const Mat&, Mat&, double);
void align(const Mat&, Mat&);
void crop(const Mat&, Mat&);

#endif
