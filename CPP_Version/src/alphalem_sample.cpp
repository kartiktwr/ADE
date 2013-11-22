
#include "opencv/cv.h"
#include "opencv/highgui.h"

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

IplImage* GetThresholdedImage(IplImage* imgHSV){
	IplImage* imgThresh = cvCreateImage(cvGetSize(imgHSV), IPL_DEPTH_8U,1);
	cvInRangeS(imgHSV,cvScalar(170,160,60), cvScalar(180,256,256), imgThresh);
	return imgThresh;
}

CvCapture* capture = 0;
bool Setup(){
	capture = cvCaptureFromCAM(0);
	if(!capture){
		cout << "Capture failure" << endl;
		return false;
	}
	cvNamedWindow("Video");
	cvNamedWindow("Ball");
	return true;
}

bool loop(){
	IplImage* frame = 0;
	frame = cvQueryFrame(capture);
	if(!frame)
		return false;
	frame = cvCloneImage(frame);
	cvSmooth(frame, frame, CV_GAUSSIAN, 3, 3);

	IplImage* imgHSV = cvCreateImage(cvGetSize(frame), IPL_DEPTH_8U, 3);
	cvCvtColor(frame, imgHSV, CV_BGR2HSV);
	IplImage* imgThresh = GetThresholdedImage(imgHSV);
	
	cvSmooth(imgThresh, imgThresh, CV_GAUSSIAN, 3, 3);

	cvShowImage("Ball", imgThresh);
	cvShowImage("Video", frame);

	cvReleaseImage(&imgHSV);
	cvReleaseImage(&imgThresh);
	cvReleaseImage(&frame);

	int c = cvWaitKey(10);
	
	if((char)c == 27){
		cvDestroyAllWindows();
		cvReleaseCapture(&capture);
		return false;
	}
	return true;
}

