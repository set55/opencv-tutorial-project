#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cout << "Usage: " << argv[0] << " <image_path>" << endl;
        return -1;
    }

    Mat A, C;                          // creates just the header parts
    A = imread(argv[1], IMREAD_COLOR); // here we'll know the method used (allocate matrix)

    if (A.empty())
    {
        cout << "Could not open or find the image" << endl;
        return -1;
    }

    Mat B(A); // Use the copy constructor

    C = A; // Assignment operator
    // imshow("Display Image", A);
    // waitKey(0);

    // imshow("Display Image", B);
    // waitKey(0);

    // imshow("Display Image", C);
    // waitKey(0);

    Mat D(A, Rect(10, 10, 100, 100));     // using a rectangle
    Mat E = A(Range::all(), Range(1, 50)); // using row and column boundaries

    // imshow("Display Image", D);
    // waitKey(0);

    // imshow("Display Image", E);
    // waitKey(0);


    Mat M(3,2, CV_8UC3, Scalar(0,0,255));
    cout << "M = " << endl << " " << M << endl << endl;

    int sz[3] = {3,2,2};
    Mat L(3,sz, CV_8UC(1), Scalar::all(0));
    // cout << "L = " << endl << " " << format(L, Formatter::FMT_NUMPY) << endl << endl;

    cout << "program end" << endl;
    return 0;
}