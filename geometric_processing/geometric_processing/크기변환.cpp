#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat src = imread("./lenna.jpg");
	Mat dst = Mat();

	resize(src, dst, Size(), 2.0, 1.0);

	imshow("Image", src);
	imshow("Scaled", dst);
	waitKey();
	return 1;
}