
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
    rapidcsv::Document doc("colhdr.csv", rapidcsv::LabelParams(0, 0),
                           rapidcsv::SeparatorParams(), rapidcsv::ConverterParams(true));

    auto dates = doc.GetColumn<int>("DATE");
    auto tavg = doc.GetColumn<float>("TAVG");
    auto tmin = doc.GetColumn<float>("EMNT");
    auto tmax = doc.GetColumn<float>("EMXT");

    auto axes = CvPlot::makePlotAxes();
    axes.create<CvPlot::Series>(dates, tavg, "-g");
    axes.create<CvPlot::Series>(dates, tmin, "-g");
    axes.create<CvPlot::Series>(dates, tmax, "-g");

    axes.yLabel("Temperatur in Degree");
    axes.xLabel("Year");
    axes.title("Weather in Konstanz over the years");
    cv::Mat plot = axes.render(600, 800);
    cv::imwrite(std::string(OUTPATH) + "/plot.png", plot);  
}
