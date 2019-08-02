#include<opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat src = imread("./lenna.jpg", IMREAD_COLOR);
	Mat dst = Mat();
	Size dsize = Size(src.cols, src.rows);

	Mat M(2, 3, CV_32F);

	M.at<float>(0, 0) = 1;
	M.at<float>(0, 1) = 0; // x축으로 미는 곳
	M.at<float>(0, 2) = 0;

	M.at<float>(1, 0) = 0.1;// y축으로 미는 곳
	M.at<float>(1, 1) = 1;
	M.at<float>(1, 2) = 0;

	warpAffine(src, dst, M, dsize, INTER_LINEAR);

	imshow("src", src);
	imshow("dst", dst);
	waitKey(0);
	return 1;

}