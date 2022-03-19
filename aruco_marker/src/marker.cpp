#include <opencv2/highgui.hpp>
#include <opencv2/aruco.hpp>
#include <stdlib.h>

using namespace cv;

int main(int argc, char *argv[])
{

    if (argc < 5)
    {
        return -1;
    }

    int dictID = strtol(argv[1], NULL, 10);
    int markerId = strtol(argv[2], NULL, 10);
    int markerSize = strtol(argv[3], NULL, 10);
    String outputImg = argv[4];

    Ptr<aruco::Dictionary> dictionary =
        aruco::getPredefinedDictionary(dictID);

    Mat markerImg;
    aruco::drawMarker(dictionary, markerId, markerSize, markerImg);

    imshow("marker", markerImg);
    waitKey(0);

    imwrite(outputImg, markerImg);

    return 0;
}