#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
	Mat src = imread("./lenna.jpg");
	Mat dst = Mat::zeros(Size(src.cols, src.rows), src.type());
	int moveX, moveY;
	cout << "x������ �����̵��մϴ�. x���� �Է��ϼ���: "; cin >> moveX;
	cout << "y������ �����̵��մϴ�. y���� �Է��ϼ���: "; cin >> moveY;

	for (int y = 0; y < src.rows; y++) {
		for (int x = 0; x < src.cols; x++) {
			const int newX = x + moveX;
			const int newY = y + moveY;
			if (newX > 0 && newY > 0 && newX < src.cols && newY < src.rows)
				dst.at<Vec3b>(newY, newX) = src.at<Vec3b>(y, x);
		}
	}
	imshow("src", src);
	imshow("dst", dst);
	waitKey(0);
	return 1;
}
