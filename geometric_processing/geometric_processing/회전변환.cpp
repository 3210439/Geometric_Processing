#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat src = imread("./lenna.jpg");
	Mat dst = Mat();
	Size dsize = Size(src.cols, src.rows);

	Point center = Point(src.cols / 2.0, src.rows / 2.0);
	Mat M = getRotationMatrix2D(center, 45, 1.0);
	warpAffine(src, dst, M, dsize, INTER_LINEAR);

	imshow("Image", src);
	imshow("Rotated", dst);
	waitKey(0);
	return 1;
}