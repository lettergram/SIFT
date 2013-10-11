#include <opencv/cv.h>
#include <opencv2/features2d/features2d.hpp>
#include <opencv/highgui.h>
#include <opencv2/nonfree/nonfree.hpp>
#include <opencv2/opencv.hpp>

/* version 2.4 of openCV */

int main(int argc, const char* argv[])
{
    const cv::Mat input = cv::imread(argv[1], 0); //Load as grayscale and pick name

    cv::SIFT detector;
    std::vector<cv::KeyPoint> keypoints;
    detector.detect(input, keypoints);

    // Add results to image and save.
    cv::Mat output;
    cv::drawKeypoints(input, keypoints, output);
    cv::imwrite("sift_result.jpg", output);

    return 0;
}
