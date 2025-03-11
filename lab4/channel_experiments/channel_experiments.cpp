#include<opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    //считывание фото
    Mat image = imread("../../input/image_1.jpg");

    //разделение фото на 3 канала
    Mat channels[3];
    split(image, channels);

    // Поиск контуров на синем канале
    vector<vector<Point>> contours1;
    vector<Vec4i> hierarchy1;
    findContours(channels[0], contours1, hierarchy1, RETR_TREE, CHAIN_APPROX_NONE);
    //Отрисовка контуров на синем канале
    Mat image_contour_blue = image.clone();
    drawContours(image_contour_blue, contours1, -1, Scalar(0, 255, 0), 2);
    imshow("Contour detection using blue channels only", image_contour_blue); //Отображение и сохранение результата для синего канала
    waitKey(0);
    imwrite("blue_channel.jpg", image_contour_blue);
    destroyAllWindows();

    //Поиск контуров на зелёном канале
    vector<vector<Point>> contours2;
    vector<Vec4i> hierarchy2;
    findContours(channels[1], contours2, hierarchy2, RETR_TREE, CHAIN_APPROX_NONE);
    //Отрисовка контуров на зелёном канале
    Mat image_contour_green = image.clone();
    drawContours(image_contour_green, contours2, -1, Scalar(0, 255, 0), 2);
    imshow("Contour detection using green channels only", image_contour_green); //Отображение и сохранение результата для зелёного канала
    waitKey(0);
    imwrite("green_channel.jpg", image_contour_green);
    destroyAllWindows();

    //Поиск контуров на красном канале
    vector<vector<Point>> contours3;
    vector<Vec4i> hierarchy3;
    findContours(channels[2], contours3, hierarchy3, RETR_TREE, CHAIN_APPROX_NONE);
    // Отрисовка контуров на красном канале
    Mat image_contour_red = image.clone();
    drawContours(image_contour_red, contours3, -1, Scalar(0, 255, 0), 2);
    imshow("Contour detection using red channels only", image_contour_red); //Отображение и сохранение результата для красного канала
    waitKey(0);
    imwrite("red_channel.jpg", image_contour_red);
    destroyAllWindows();
}
