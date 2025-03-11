#include<opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {

    Mat image = imread("../../input/image_1.jpg");
    //Преобразование изображения в градации серого
    Mat img_gray;
    cvtColor(image, img_gray, COLOR_BGR2GRAY);
    //Применение бинарной пороговой обработки
    Mat thresh;
    threshold(img_gray, thresh, 150, 255, THRESH_BINARY); //Отображение и сохранение бинарного изображения
    imshow("Binary mage", thresh);
    waitKey(0);
    imwrite("image_thres1.jpg", thresh);
    destroyAllWindows();

    //Поиск контуров с использованием CHAIN_APPROX_NONE
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(thresh, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE);
    //Отрисовка контуров на оригинальном изображении
    Mat image_copy = image.clone();
    drawContours(image_copy, contours, -1, Scalar(0, 255, 0), 2);
    imshow("None approximation", image_copy); //Отображение и сохранение результата
    waitKey(0);
    imwrite("contours_none_image1.jpg", image_copy);
    destroyAllWindows();


    //Поиск контуров с использованием CHAIN_APPROX_SIMPLE
    vector<vector<Point>> contours1;
    vector<Vec4i> hierarchy1;
    findContours(thresh, contours1, hierarchy1, RETR_TREE, CHAIN_APPROX_SIMPLE);
    //Отрисовка контуров на оригинальном изображении
    Mat image_copy1 = image.clone();
    drawContours(image_copy1, contours1, -1, Scalar(0, 255, 0), 2);
    imshow("Simple approximation", image_copy1); //Отображение и сохранение результата
    waitKey(0);
    imwrite("contours_simple_image1.jpg", image_copy1);
    destroyAllWindows();
