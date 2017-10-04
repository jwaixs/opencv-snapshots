#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace std;

int main(int argc, char **argv) {
	cv::Mat image = cv::imread(argv[1]);

	if (!image.data) {
		std::cout << "Image file not found" << endl;
		return 1;
	}

	cv::Mat gray_image_8bit, gray_image_16bit;
	cv::cvtColor(image, gray_image_8bit, CV_BGR2GRAY);
	gray_image_8bit.convertTo(gray_image_16bit, CV_16U, 255);

	cv::imshow("image in 8-bits", image);
	cv::imshow("image in grayscale 8-bits", gray_image_8bit);
	cv::imshow("image in grayscale 16-bits", gray_image_16bit);

	cv::imwrite("image_8bit.png", gray_image_8bit);
	cv::imwrite("image_16bit.png", gray_image_16bit);

	cv::waitKey(0);

	return 0;
}
