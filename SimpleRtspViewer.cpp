// SimpleRtspViewer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>

// opencv 
#include <opencv2/opencv.hpp>

// list
#include <list>

// thread
#include <thread>

bool isRun = false;
std::list<cv::Mat> frames;

// thread function for video show
void drawFrame(bool isRun)
{
	while (isRun) {
		if (frames.size() > 1) {
			cv::imshow("RTSP window", frames.front());
			frames.pop_front();
			cv::waitKey(10);
		}
	}
}

int main(int argc, char *argv[])
{
	std::string streamURL;

	if (argc > 1) {
		///std::string streamURL = "rtsp://10.1.0.10/liveMain";
		streamURL = argv[1];
	}

	cv::VideoCapture stream(streamURL, cv::CAP_FFMPEG);

	if (!stream.isOpened()) {
		std::cerr << "Stream open failed : " << streamURL << std::endl;
		return EXIT_FAILURE;
	}

	isRun = true;

	std::thread DrawThread(drawFrame, isRun);
	DrawThread.detach();

	cv::Mat inFrame;
	while (stream.read(inFrame)) {
		frames.push_back(inFrame.clone());
		printf("%d frame in stack\n", (int)frames.size());
	}

	isRun = false;
	
	return EXIT_SUCCESS;
}