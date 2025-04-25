#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	Mat img, img1, hist;
		img = imread("D:/opencv_test/test.jpg");
	if (img.empty())
		cout << "Image not found" << endl;
	cvtColor(img, img1, COLOR_BGR2GRAY);
	imshow("Gray_image", img1);
	int hight_size = 256;
	float ranges[] = { 0,256 };
	const float* histranges = { ranges };
	calcHist(&img1, 1, 0, Mat(), hist, 1, &hight_size, &histranges, true, false);
	int hist_h = 300;
	int hist_w = 512; 
	int bin_w = 2;
	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));
	normalize(hist, hist, 0, hist_h, NORM_MINMAX, -1, Mat());
	for (int i = 1; i < hight_size ; i++)
	{
		line(histImage, Point((i - 1) * bin_w, hist_h - cvRound(hist.at<float>(i - 1))),
			Point((i)*bin_w, hist_h - cvRound(hist.at<float>(i))), Scalar(255, 0, 0), 2, 8, 0);
	}
	imshow("histImage", histImage);

	waitKey(0); 
	return 0;
}
