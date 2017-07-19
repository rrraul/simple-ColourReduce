

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


void colourReduce (cv::Mat &image, int div=64) {
	
	int nl = image.rows;
	int nc = image.cols * image.channels();
	
	for (int j=0; j<nl; j++) {
	
		uchar * data = image.ptr<uchar>(j);

		for (int i = 0; i < nc; i++) {

			data[i] = data[i]/div*div + div/2;

		}

	}
	
}


int main (int argc, char ** argv) {

	string filename = "data/images/image.jpg";

	if (argc == 2) {
		filename = argv[1];		
	}
	
	Mat image = imread (filename);
	
	colourReduce (image);
	
	namedWindow ("Image");
	imshow ("Image", image);
	
	waitKey(0);
	destroyAllWindows();
	
	imwrite ("results/image-reduce.jpg", image);
	return 0;
	
}

