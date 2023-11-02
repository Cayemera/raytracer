#include "include/ppmWriter.hpp"
#include <complex.h>
#include <tgmath.h>
#include "include/patterns.hpp"
#include "../timer/include/timerKeeper.hpp"
//g++ testWrite.cpp src/*.cpp -o Tester


int main(){
    TimerKeeper test_timers;
    Timer * timer1 = test_timers.makeTimer("PpmWriter",  "Writes the output PPM file");
    Timer * timer2 = test_timers.makeTimer("PpmWriter2",  "Writes the output PPM file");
    Timer * timer3 = test_timers.makeTimer("PpmWriter3",  "Writes the output PPM file");
    Timer * timer4 = test_timers.makeTimer("PpmWriter4",  "Writes the output PPM file");


    char *name = "cody";
    std::string comment = "sup";
    PpmWriter imageWriter;
    imageWriter.setNameSchemeAuto();
    if(imageWriter.setOutputPath("output_images/")){
        return 1;
    }    

    Color test_color;
    test_color.push_back(255);
    test_color.push_back(120);
    test_color.push_back(180);
    std::cout << "Generating PPM..." << std::endl;
    timer1->start();
    imageWriter.write(name,1920,1080,255,comment,julia);
    timer1->end();
    std::cout << std::endl;
    std::cout << "PPM Generated!" << std::endl;
    std::cout << "Time taken: " << timer1->getTime() ;
    std::cout << " sec " << std::endl;
    timer2->start();
    imageWriter.write(name,1920,1080,255,comment,mandlebrot);
    timer2->end();
    std::cout << std::endl;
    std::cout << "PPM Generated!" << std::endl;
    std::cout << "Time taken: " << timer2->getTime() ;
    std::cout << " sec " << std::endl;
    timer3->start();
    imageWriter.write(name,1920,1080,255,comment,squares);
    timer3->end();
    std::cout << std::endl;
    std::cout << "PPM Generated!" << std::endl;
    std::cout << "Time taken: " << timer3->getTime() ;
    std::cout << " sec " << std::endl;
    timer4->start();
    imageWriter.write(name,1920,1080,255,comment,checkers);
    timer4->end();
    std::cout << std::endl;
    std::cout << "PPM Generated!" << std::endl;
    std::cout << "Time taken: " << timer4->getTime() ;
    std::cout << " sec " << std::endl;

    std::cout << "Total Time Taken: " << test_timers.getTotalTime() << " sec" << std::endl;

    test_timers.displayResults();

}