#include <opencv2/highgui.hpp>
#include <opencv2/aruco.hpp>
#include <stdlib.h>

using namespace cv;

int main(int argc, char *argv[])
{

    if (argc < 7)
    {
        return -1;
    }

    int rows = strtol(argv[1], NULL, 10);
    int columns = strtol(argv[2], NULL, 10);
    int dictionaryId = strtol(argv[3], NULL, 10);
    int markerSize = strtol(argv[4], NULL, 10);
    int markerSeparation = strtol(argv[5], NULL, 10);
    int margins = (markerSeparation / 2);
    String outputImg = argv[6];

    Size imageSize;
    imageSize.height = rows * (markerSize);
    imageSize.width = columns * (markerSize);

    Ptr<aruco::Dictionary> dictionary = aruco::getPredefinedDictionary(dictionaryId);

    Ptr<aruco::GridBoard> board = aruco::GridBoard::create(columns, rows, float(markerSize),
                                                           float(markerSeparation), dictionary);

    // show created board
    Mat boardImg;
    board->draw(imageSize, boardImg, margins);

    imshow("Aruco Board", boardImg);
    waitKey(0);

    imwrite(outputImg, boardImg);

    return 0;
}