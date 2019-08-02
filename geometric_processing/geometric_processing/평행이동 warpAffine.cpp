#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat src = imread("./lenna.jpg");
	Mat dst = Mat();

	int tx = 100;
	int ty = 20;

	Mat tmat = (Mat_<double>(2, 3) << 1, 0, tx, 0, 1, ty);
	warpAffine(src, dst, tmat, src.size());

	imshow("src", src);
	imshow("dst", dst);
	waitKey(0);
	return 1;
}