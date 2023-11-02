

#include <chrono>
#include <bits/stdc++.h>

class Timer{
    private:
        int id;
        std::string name;
        std::string note;
        std::chrono::time_point<std::chrono::system_clock> start_time, end_time;
    public:
        Timer(){};
        Timer(int id, std::string name, std::string note){this->id = id; this->name = name; this->note = note;}; //constructor
        ~Timer(){};
        // void start(){time(&start_time); std::ios_base::sync_with_stdio(false);}
        //getters
        std::string getName(){return name;}
        std::string getNote(){return note;}
        void start(){start_time = std::chrono::system_clock::now();}
        void end(){end_time = std::chrono::system_clock::now();}
        double getTime(){if(end_time.time_since_epoch() == decltype(end_time)::duration::zero()) return -1.0; std::chrono::duration<double> elapse = (end_time - start_time); return elapse.count();}
};