#include <opencv2/opencv.hpp>
#include <opencv2/aruco.hpp>
#include <iostream>
#include <cstdlib>

namespace
{
    const char *keys =
        "{d        |16    | DICT_ARUCO_ORIGINAL = 16}";
}

int main(int argc, char **argv)
{
    cv::CommandLineParser parser(argc, argv, keys);

    int dictionaryId = parser.get<int>("d");
    int wait_time = 10;
    cv::String videoInput = "0";
    cv::VideoCapture in_video;

    in_video.open(0);

    if (!in_video.isOpened())
    {
        std::cerr << "failed to open video input: " << videoInput << std::endl;
        return 1;
    }

    cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(dictionaryId);

    while (in_video.grab())
    {
        cv::Mat img, c_img;
        in_video.retrieve(img);
        img.copyTo(c_img);
        std::vector<int> ids;
        std::vector<std::vector<cv::Point2f>> corners;
        cv::aruco::detectMarkers(img, dictionary, corners, ids);

        if (ids.size() > 0)
            cv::aruco::drawDetectedMarkers(c_img, corners, ids);

        imshow("Detected markers", c_img);
        char key = (char)cv::waitKey(wait_time);
        if (key == 27)
            break;
    }

    in_video.release();

    return 0;
}