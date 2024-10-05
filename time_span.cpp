


#include <iostream>
#include <string>
#include "time_span.h"
using namespace std;


TimeSpan::TimeSpan(int hours, int minutes, int seconds) {
    int total_seconds = 0;
    total_seconds += hours * 3600;
    total_seconds += minutes * 60;
    total_seconds += seconds;

    //set times
    this->hours_ = total_seconds / 3600;
    total_seconds = total_seconds % 3600;

    this->minutes_  = total_seconds / 60;
    total_seconds = total_seconds % 60;

    this->seconds_ = total_seconds;
}

TimeSpan::TimeSpan(int minutes, int seconds) {
    int total_seconds = 0;
    total_seconds += minutes * 60;
    total_seconds += seconds;

    this->hours_ = total_seconds / 3600;
    total_seconds = total_seconds % 3600;

    this->minutes_  = total_seconds / 60;
    total_seconds = total_seconds % 60;

    this->seconds_ = total_seconds;

}


TimeSpan::TimeSpan(int seconds) {
    int total_seconds = seconds;
    //set times
    this->hours_ = total_seconds / 3600;
    total_seconds = total_seconds % 3600;

    this->minutes_  = total_seconds / 60;
    total_seconds = total_seconds % 60;

    this->seconds_ = total_seconds;
}


//getters
TimeSpan::TimeSpan() 
    : minutes_(0), hours_(0), seconds_(0) {}


int TimeSpan::hours() const {
    return this->hours_;
}
        
int TimeSpan::minutes() const {
    return this->minutes_;
}

int TimeSpan::seconds() const {
    return this->seconds_;
}


//setters
 void TimeSpan::set_time(int hours, int minutes, int seconds){
    int total_seconds = 0;
    total_seconds += hours * 3600;
    total_seconds += minutes * 60;
    total_seconds += seconds;

    //set times
    this->hours_ = total_seconds / 3600;
    total_seconds = total_seconds % 3600;

    this->minutes_  = total_seconds / 60;
    total_seconds = total_seconds % 60;

    this->seconds_ = total_seconds;
}






