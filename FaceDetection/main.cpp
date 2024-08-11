#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include<iostream>

using namespace std;
using namespace cv;

/*void main() {
	string path = "iskcon.jpg";
	Mat img = imread(path);
	imshow("Frame", img);
	waitKey(0); 
}*/

/*int main() {
    VideoCapture video(0); // Use 0 for the default camera

    if (!video.isOpened()) {
        cerr << "Error: Could not open the camera" << endl;
        return -1;
    }

    Mat img;
    while (true) {
        if (!video.read(img)) {
            cerr << "Error: Could not read frame" << endl;
            break;
        }

        if (img.empty()) {
            cerr << "Error: Empty frame" << endl;
            break;
        }

        imshow("Frame", img);
        if (waitKey(1) >= 0) break; // Exit loop on any key press
    }

    return 0;
}*/


////////face detect////////
void main() {
    VideoCapture video(1);
    CascadeClassifier facedetect;
    facedetect.load("haarcascade_frontalface_default.xml");

    while (true) {
        vector<Rect> faces;

        facedetect.detectMultiScale(img, faces, 1.3, 5);

        cout << faces.size() << endl;

        for (int i = 0; i < faces.size(); i++) {
            rectangle(img, faces[i].t1(), faces[i].br(), scalar(50, 50, 225), 3);
            putText(img, to_string(faces.size()), point(10,40), FONT_HERSHEY_DUPLEX, 1, Scalar(255, 255, 255);
        }

        imshow("Frame", img);
        waitKey(10);
    
    }
}


/*
int main() {
    // Load the face cascade classifier
    CascadeClassifier face_cascade;
    if (!face_cascade.load("haarcascade_frontalface_default.xml")) {
        cerr << "Error loading cascade file" << endl;
        return -1;
    }

    // Open the default camera
    VideoCapture capture(0);
    if (!capture.isOpened()) {
        cerr << "Error opening video capture" << endl;
        return -1;
    }

    // Loop through the video frames
    while (true) {
        // Capture a frame from the camera
        Mat frame;
        capture >> frame;

        // Convert the frame to grayscale
        Mat gray;
        cvtColor(frame, gray, COLOR_BGR2GRAY);

        // Detect faces in the grayscale frame
        vector<Rect> faces;
        face_cascade.detectMultiScale(gray, faces, 1.3, 5);

        // Draw rectangles around the detected faces
        for (size_t i = 0; i < faces.size(); i++) {
            rectangle(frame, faces[i], Scalar(0, 255, 0), 2);
        }

        // Display the frame with the detected faces
        imshow("Face Detection", frame);

        // Exit the loop if the 'q' key is pressed
        if (waitKey(1) == 'q') {
            break;
        }
    }

    // Release the video capture and destroy all windows
    capture.release();
    destroyAllWindows();

    return 0;
}


