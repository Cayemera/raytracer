#include "include/ppmWriter.hpp"
#include <complex.h>
#include <tgmath.h>
#include "include/patterns.hpp"



int main(){
    char *name = "cody";
    std::string comment = "sup";
    PpmWriter imageWriter;
    imageWriter.setNameSchemeAuto();
    Color test_color;
    test_color.push_back(255);
    test_color.push_back(120);
    test_color.push_back(180);
    //imageWriter.write(name,120,110,255,comment,test_color); //Constant color
    std::cout << "Generating PPM..." << std::endl;
    imageWriter.write(name,1920,1080,255,comment,julia);
    std::cout << std::endl;
    std::cout << "PPM Generated!" << std::endl;

}