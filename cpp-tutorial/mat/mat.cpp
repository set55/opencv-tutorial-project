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

    if (A.empty()) {
        cout << "Could not open or find the image" << endl;
        return -1;
    }

    Mat B(A); // Use the copy constructor

    C = A; // Assignment operator
    imshow("Display Image", A);
    waitKey(0);

    imshow("Display Image", B);
    waitKey(0);

    imshow("Display Image", C);
    waitKey(0);

    






    cout << "program end" << endl;
    return 0;
}