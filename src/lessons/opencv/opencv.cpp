#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"
#include <opencv2/imgcodecs.hpp>
#include "opencv2/imgcodecs.hpp"

auto main() -> int
{
    cv::Mat img = cv::imread(std::string(IMPATH) + "/horror_kid.jpg"); 

    cv::Mat edges;
    cv::Mat img_gray;
    cv::cvtColor(img, img_gray, cv::COLOR_BGR2GRAY);

    cv::Canny(img_gray, edges, 180, 300);

    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hiearchy;
    cv::findContours(edges, contours, hiearchy, cv::RETR_TREE, cv::CHAIN_APPROX_NONE);

    cv::drawContours(img, contours, -1, cv::Scalar(0,0,255), 2);

    cv::putText(img, "Edges", cv::Point(15, 70), cv::FONT_HERSHEY_PLAIN, 3, cv::Scalar(255, 255, 255), 4);
    // cv::GaussianBlur(img, edges,cv::Size(5,5), 0);

    cv::imwrite(std::string(OUTPATH) + "/opencv_canny.jpg", img);
    
    return 0;
}