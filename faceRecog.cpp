//g++ faceRecog.cpp -o faceRecog `pkg-config --cflags --libs opencv4
#include <opencv2/opencv.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>

int main() {
    cv::CascadeClassifier face_cascade;
    if (!face_cascade.load("/usr/share/opencv4/haarcascades/haarcascade_frontalface_alt.xml")) {
        std::cerr << "Error loading face cascade\n";
        return -1;
    }

    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        std::cerr << "Error opening camera\n";
        return -1;
    }

    cv::Mat frame;

    while (true) {
        cap >> frame;
        std::vector<cv::Rect> faces;
        face_cascade.detectMultiScale(frame, faces); // Detect faces

        for (auto &face : faces) {
            cv::rectangle(frame, face, cv::Scalar(255,0,0));
        }

        cv::imshow("Face Detection", frame); // Display the result

        // Exit loop if 'ESC' key is pressed
        if (cv::waitKey(30) >= 0) break;
    }

    return 0;
}