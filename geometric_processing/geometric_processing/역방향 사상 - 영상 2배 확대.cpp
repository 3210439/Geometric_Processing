#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
	Mat src = imread("./lenna.jpg");
	Mat dst = Mat::zeros(Size(src.cols*2, src.rows*2), src.type());

	for (int y = 0; y < dst.rows; y++)
	{
		for (int x = 0; x < dst.cols; x++) {
			const int newX = x / 2.0;
			const int newY = y / 2.0;
			dst.at<Vec3b>(y,x) = src.at<Vec3b>(newY, newX);

		}
	}
	imshow("src", src);
	imshow("dst", dst);
	waitKey();
	return 0;
}
