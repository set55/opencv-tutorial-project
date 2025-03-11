#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
    VideoCapture cap;  // VideoCapture object

    // Check if user provided a video file as an argument
    if (argc > 1) {
        cap.open(argv[1]);  // Open video file
    } else {
        cap.open(0);  // Open default webcam (device 0)
    }

    // Check if the camera or file opened successfully
    if (!cap.isOpened()) {
        cout << "Error: Could not open video source!" << endl;
        return -1;
    }

    Mat frame;  // Matrix to store each frame
    while (true) {
        cap >> frame;  // Capture a new frame

        if (frame.empty()) {
            cout << "End of video or camera disconnected!" << endl;
            break;  // Exit loop if no frame is captured
        }

        imshow("Video Stream", frame);  // Show frame in a window

        // Press 'q' to exit
        if (waitKey(30) == 'q') {
            break;
        }
    }

    cap.release();  // Release video capture object
    destroyAllWindows();  // Close all OpenCV windows

    return 0;
}
