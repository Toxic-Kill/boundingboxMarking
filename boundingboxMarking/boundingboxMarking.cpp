#include <iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	cv::Mat srcMat = cv::imread("D:\\Files\\coins.png");//读取图片
	cv::Mat binMat;
	cv::Mat labMat;
	cv::Mat staMat;
	cv::Mat cenMat;
	cv::threshold(srcMat, binMat, 100, 255, THRESH_BINARY);//二值化
	int num = cv::connectedComponentsWithStats(binMat, labMat, staMat, cenMat,8);//连通域标记
	for (int i = 1; i < num; i++)//画出连通域
	{
		cv::Rect bndbox;
		bndbox.x = staMat.at<int>(i, 0);
		bndbox.y = staMat.at<int>(i, 1);
		bndbox.width = staMat.at<int>(i, 2);
		bndbox.height = staMat.at<int>(i, 3);
		cv::rectangle(srcMat, bndbox, CV_RGB(255, 0, 0), 1, 8, 0);
	}
	std::cout << "The number of coins is:" << num - 1 << endl;//显示物件个数
	cv::imshow("srcMat", srcMat);//显示标记连通域后的图像
	waitKey(0);
}