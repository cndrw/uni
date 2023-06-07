
#define CVPLOT_HEADER_ONLY
#include <iostream>
#include <CvPlot/cvplot.h>
#include "rapidcsv.h"
#include <vector>
#include "opencv2/highgui/highgui.hpp"
#include <memory>
#include "opencv2/opencv.hpp"
#include <opencv2/imgcodecs.hpp>

auto main() -> int
{
    rapidcsv::Document doc("colhdr.csv");
    std::vector<float> col = doc.GetColumn<float>("DATE");
    std::vector<float> row = doc.GetColumn<float>("TAVG");
    auto axes = CvPlot::makePlotAxes();
    axes.create<CvPlot::Series>(row, col, "-g");
    // auto axes = CvPlot::plot(std::vector<double>{3, 3, 4, 6, 4, 3}, "-o");
    cv::Mat plot = axes.render(300,400);
    cv::imwrite(std::string(OUTPATH) + "/plot.jpg", plot);  
}
