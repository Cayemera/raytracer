#include <iostream>
#include <vector> //may not need this
#include <math.h>
#include <functional>
#include <string>

// this will get it to shutup for now
typedef std::vector<int> Color;



class PpmWriter{
    public:
        //Write an array of colors representing an Image or Rendering at every pixel coordinate
        int write(int width, int height, int color_max, std::string comments, Color image[]){};
        //Write a constant color at every pixel coordinate
        int write(int width, int height, int color_max, std::string comments, Color color_const){};
        //Write a PPM following the rule which is defined by another function taking the pixel coordinates
        int write(int width, int height, int color_max, std::string comments, std::function<void (int,int)> rule){};

    private:

};