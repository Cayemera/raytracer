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
    imageWriter.write(name,500,500,255,comment,checkers);

}