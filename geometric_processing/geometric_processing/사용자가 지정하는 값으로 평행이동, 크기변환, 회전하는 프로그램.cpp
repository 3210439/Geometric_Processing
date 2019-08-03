#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat lenna, dst;
int x=1, y=1;
double sizeXY;
int size_int=100;
Mat tmat;
Point center;
Mat M;
int gradient=0;

void onTrackbar_warp(int, void*)
{
	tmat = (Mat_<double>(2, 3) << 1, 0, x, 0, 1, y);
	warpAffine(lenna, dst, tmat, lenna.size());
	imshow("lenna", dst);
}

void onTrackbar_size(int, void*)
{
	sizeXY = (double)size_int / 100.0;
	resize(lenna, dst, Size(), sizeXY, sizeXY);
	imshow("lenna", dst);
}

void onTrackbar_rotation(int, void*)
{
	center = Point(lenna.cols / 2.0, lenna.rows / 2.0);
	M = getRotationMatrix2D(center, gradient, 1.0);
	warpAffine(lenna, dst, M, Size(lenna.cols, lenna.rows), INTER_LINEAR);
	imshow("lenna", dst);
}

int main()
{
	lenna = imread("lenna.jpg");
	imshow("lenna", lenna);
	createTrackbar("x�� �̵�", "lenna", &x, 400, onTrackbar_warp);
	createTrackbar("y�� �̵�", "lenna", &y, 225, onTrackbar_warp);
	createTrackbar("ũ�⺯ȯ", "lenna", &size_int, 200, onTrackbar_size);
	createTrackbar("������ȯ", "lenna", &gradient, 360, onTrackbar_rotation);
	waitKey();
}