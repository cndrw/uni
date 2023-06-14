
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
    rapidcsv::Document doc("uncertainty.csv"); 

    auto x_values = doc.GetColumn<float>("x values");
    auto y_values = doc.GetColumn<float>("y values");

    auto axes = CvPlot::makePlotAxes();
    axes.create<CvPlot::Series>(x_values, y_values, ".r");

    axes.xLabel("x-Axes");
    axes.yLabel("y-Axes");
    axes.title("Uncertainty Ellipse");
    cv::Mat plot = axes.render(600, 800);
    cv::imwrite(std::string(OUTPATH) + "/uncertaintyplot.png", plot);  
}
