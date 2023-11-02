#include "../include/patterns.hpp"

Color mandlebrot(int x, int y, int width, int height){
    double minR = -1.5;
    double maxR = 0.7;
    double minI = -1.0;
    double maxI = 1.0;
    double cReal = x * ((maxR - minR) / width) + minR;
    double cImag = y * ((maxI - minI) / height) + minI;
    int i =0;
    double zReal = 0.0, zImag = 0.0;
    int maxIter = 1000;
    while(i<maxIter && zReal * zReal + zImag * zImag < 4.0){
        double temp = zReal * zReal  - zImag * zImag + cReal;
        zImag = 2.0 * zReal * zImag + cImag;
        zReal = temp;
        i++;
    }
    int r = (i * 5) % 255;
    int g = (i * 20) % 255;
    int b = (i * 10) % 255;
    Color new_color;
    new_color.push_back(r);
    new_color.push_back(g);
    new_color.push_back(b);
    return new_color;
}

Color julia(int x, int y, int width, int height){
    Color new_color;
    double minR = -2.0;
    double maxR = 2.0;
    double minI = -1.0;
    double maxI = 1.0;
    double zReal = x * ((maxR - minR) / width) + minR;
    double zImag = y * ((maxI - minI) / height) + minI;
    double cReal = -.79;
    double cImag = .15;
    //double cReal = .28;
    //double cImag = .008;
    int i = 0;
    int maxIter = 3000;
    while(i<maxIter && zReal * zReal + zImag * zImag < 4.0){
        double temp = zReal * zReal  - zImag * zImag + cReal;
        zImag = 2.0 * zReal * zImag + cImag;
        zReal = temp;
        i++;
    }
    i = i - log2(log2(zReal * zReal + zImag * zImag));
    int r = i % 255;
    int g = i % 255;
    int b = (i * 3) % 255;
    new_color.push_back(r);
    new_color.push_back(g);
    new_color.push_back(b);
    return new_color;
}

Color squares(int x, int y, int width, int height){
    Color new_color;
    int square_size = 25;
    int hSquare = x / square_size;
    int vSquare = y /square_size;
    if(hSquare % 2 != 0 && vSquare % 2!=0){
        new_color.push_back(0);
        new_color.push_back(0);
        new_color.push_back(0);
    }
    else{
        new_color.push_back(255);
        new_color.push_back(255);
        new_color.push_back(255);
    }
    return new_color;
}

Color checkers(int x, int y, int width, int height){
    Color new_color;
    int square_size = 25;
    int hSquare = x / square_size;
    int vSquare = y /square_size;
    if(vSquare % 2 == 0){
        if(hSquare % 2 == 0){
            new_color.push_back(0);
            new_color.push_back(0);
            new_color.push_back(0);
        }
        else{
            new_color.push_back(255);
            new_color.push_back(255);
            new_color.push_back(255);
        }
    }
    else{
        if(hSquare % 2 != 0){
            new_color.push_back(0);
            new_color.push_back(0);
            new_color.push_back(0);
        }
        else{
            new_color.push_back(255);
            new_color.push_back(255);
            new_color.push_back(255);
        }
    }
    return new_color;
}