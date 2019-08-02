#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
	Mat src = imread("./lenna.jpg", IMREAD_GRAYSCALE);
	int rows = src.rows;
	int cols = src.cols;
	Mat dst = src.clone();

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			int offset_x = (int)(25.0 * sin(2 * 3.14 * i / 180));
			int offset_y = 0;
			if (j + offset_x < rows)
				dst.at<uchar>(i, j) = src.at<uchar>(i, (j + offset_x) % cols);
			else {
				dst.at<uchar>(i, j) = 0;
			}
		}
	}

	imshow("src", src);
	imshow("dst", dst);

	waitKey(0);
}
