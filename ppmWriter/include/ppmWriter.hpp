#include <iostream>
#include <fstream>
#include <sstream>
#include <vector> //may not need this
#include <math.h>
#include <functional>
#include <string>
#include <chrono>
#include <complex>
#pragma once



// this will get it to shutup for now
typedef std::vector<int> Color;



class PpmWriter{
    private:
        bool auto_name_set; //Specifies naming output file automatically
        int line_length;//Max length of a line in PPM before starting a new line
        std::string getAutoFileName();
    public:
        //PpmWriter Constructor
        PpmWriter();
        //PpmWriter Destructor
        ~PpmWriter(){};
        //Set auto output file naming
        void setNameSchemeAuto(){auto_name_set = true;};
        //Set line length
        void setLineLength(int length){line_length = length;};
        //Write an array of colors representing an Image or Rendering at every pixel coordinate
        int write(std::string filename, int width, int height, int color_max, std::string comments, Color image[]);
        //Write a constant color at every pixel coordinate
        int write(std::string filename, int width, int height, int color_max, std::string comments, Color color_const);
        //Write a PPM following the rule which is defined by another function taking the pixel coordinates
        int write(std::string filename, int width, int height, int color_max, std::string comments, std::function<Color (int,int,int,int)> pattern);

};