#include <iostream>       
#include <fstream>        
#include <openssl/sha.h>  // Для функций SHA256 из OpenSSL
#include <opencv2/opencv.hpp> // Для работы с изображениями через OpenCV


std::string calculate(const cv::Mat image){ //функция для подсчета хэша изображения
    unsigned char h[SHA256_DIGEST_LENGTH]; //создание массива для хранения бинарного хэша размером SHA256_DIGEST_LENGTH
    SHA256(image.data, image.total() * image.elemSize(), h); //Вычисление хэша с помощью Openssl.
    /*Image.data - указатель на пиксели изображения
      image.total() * image.elemSize() - общий размер данных в байтах, image.total() - кол-во пикселей, image.elemSize() - общий размер данных в байтах
      h - массив для записи хэша
      */

    std::string res;
    const char* hex = "0123456789abcdef";
    for(int i = 0; i<SHA256_DIGEST_LENGTH; ++i){ //цикл по всем 32 байтам хэша
        unsigned char byte = h[i]; //текущий байт хэша
        res += hex[(byte >> 4) & 0xF]; //сдвиг вправо на 4 бита, получение соответствующего сивмола HEX
        res += hex[byte & 0xF]; //преобразование младшего полубайта
    }
    return res;
}

int main(){

    cv::Mat image = cv::imread("image.jpg"); //загрузка изображения

    std::string hsh1 = calculate(image); //вычисление хэша изображения

    cv::Mat image2 = image.clone(); //копия для изменения пикселя
    cv::Vec3b& pixel = image2.at<cv::Vec3b>(0, 0); //Получение ссылки на пиксель
    pixel[0] += 1; //увеличение синего канала на 1

    std::string hsh2 = calculate(image2); //хэш 2 изображения

    bool eq = (hsh1 == hsh2); //сравнение хэшей

    std::cout << "Orig:    " << hsh1 << std::endl;
    std::cout << "After changing:    " << hsh2 << std::endl;
    if(eq) std::cout << "equal";
    else std::cout << "not equal";

    std::ofstream file("task3.txt");
    file << "Orig:   " << hsh1 << std::endl;
    file << "After changing:   " << hsh2 << std::endl;
    if(eq) file << "equal";
    else file << "not equal";
    file.close();


    return 0;
}