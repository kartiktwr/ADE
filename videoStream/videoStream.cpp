/*
 * videoStream.cpp
 *
 *  Created on: Oct 1, 2013
 *      Author: kartik
 */


#include "opencv2/core/core.hpp"
#include "opencv2/flann/miniflann.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/photo/photo.hpp"
#include "opencv2/video/video.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/ml/ml.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/contrib/contrib.hpp"
#include "opencv2/core/core_c.h"
#include "opencv2/highgui/highgui_c.h"
#include "opencv2/imgproc/imgproc_c.h"

#include <iostream>

using namespace std;
using namespace cv;

int main(){

	VideoCapture cap;
	cap.open(0);

	if(!cap.isOpened()){
		cout << "Cannot open the video file" << endl;
		return -1;
	}

	double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH);
	double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT);

	cout << "Frame size: " << dWidth << "x" << dHeight << endl;

	namedWindow ("MyVideo", CV_WINDOW_AUTOSIZE);

	while(true){
		Mat frame;

		bool bSuccess = cap.read(frame);
		//cout << "1";

		if(!bSuccess){
			cout << "Cannot read a frame from video file" << endl;
			break;
		}

		imshow ("MyVideo", frame);

		if(waitKey(30) == 27){
			cout << "esc key is pressed by user" << endl;
			break;
		}
	}


	return 0;

}
