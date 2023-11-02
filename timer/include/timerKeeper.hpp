#include <vector>
#include "timer.hpp"
class TimerKeeper{

private:
    std::vector<Timer*> timers;
    int timer_quantity;
public:
    TimerKeeper(){timer_quantity=0;}

    Timer* makeTimer(std::string name, std::string note){
        Timer* temp = new Timer(timer_quantity,name,note);
        timers.push_back(temp);
        return temp;
    }

    double getTotalTime(){
        double total_time = 0;
        for(Timer *currTimer : timers){
            if(double end_time = currTimer->getTime(); end_time != -1){
                total_time += end_time;
            }
        }
        return total_time;
    }


    void displayResults(){
        std::string spacing = "    ";
        for(Timer *currTimer : timers){
            std::cout << currTimer->getName() << spacing << currTimer->getNote() << spacing << currTimer->getTime() << std::endl;
        }
    }
};