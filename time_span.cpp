
#include <iostream>
#include <string>
#include "time_span.h"
#include <cmath>
using namespace std;




    TimeSpan::TimeSpan(double hours, double minutes, double seconds) {

        double set_seconds = (hours * 3600 + minutes * 60 + seconds);
        int total_seconds = static_cast<int>(round(set_seconds));

        //set times
        this->hours_ = total_seconds / 3600;
        total_seconds = total_seconds % 3600;

        this->minutes_  = total_seconds / 60;
        total_seconds = total_seconds % 60;

        this->seconds_ = total_seconds;
    }

    TimeSpan::TimeSpan(double minutes, double seconds) {
        double set_seconds = (minutes * 60 + seconds);
        int total_seconds = static_cast<int>(round(set_seconds));

        this->hours_ = total_seconds / 3600;
        total_seconds = total_seconds % 3600;

        this->minutes_  = total_seconds / 60;
        total_seconds = total_seconds % 60;

        this->seconds_ = total_seconds;

    }


    TimeSpan::TimeSpan(double seconds) {

        int total_seconds = static_cast<int>(round(seconds));
        //set times
        this->hours_ = total_seconds / 3600;
        total_seconds = total_seconds % 3600;

        this->minutes_  = total_seconds / 60;
        total_seconds = total_seconds % 60;

        this->seconds_ = total_seconds;
    }

    TimeSpan::TimeSpan() 
        : minutes_(0), hours_(0), seconds_(0) {}

    //getters
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
    void TimeSpan::set_time(double new_hours, double new_minutes, double new_seconds){

        double set_seconds = (new_hours * 3600 + new_minutes * 60 + new_seconds);
        int total_seconds = static_cast<int>(round(set_seconds));
        //set times
        this->hours_ = total_seconds / 3600;
        total_seconds = total_seconds % 3600;

        this->minutes_  = total_seconds / 60;
        total_seconds = total_seconds % 60;

        this->seconds_ = total_seconds;
    }

    void TimeSpan::set_hours(double new_hours) { 
        
        double set_seconds = (new_hours * 3600 + minutes_ * 60 + seconds_);
        int total_seconds = static_cast<int>(round(set_seconds));

        this->hours_ = total_seconds / 3600;
        total_seconds = total_seconds % 3600;

        this->minutes_  = total_seconds / 60;
        total_seconds = total_seconds % 60;

        this->seconds_ = total_seconds;


    }
    void TimeSpan::set_minutes(double new_minutes) {

        double set_seconds = (hours_ * 3600 + new_minutes * 60 + seconds_);
        int total_seconds = static_cast<int>(round(set_seconds));
        
        this->hours_ = total_seconds / 3600;
        total_seconds = total_seconds % 3600;

        this->minutes_  = total_seconds / 60;
        total_seconds = total_seconds % 60;

        this->seconds_ = total_seconds;


    }
    void TimeSpan::set_seconds(double new_seconds) {
        double set_seconds = (hours_ * 3600 + minutes_ * 60 + new_seconds);
        int total_seconds = static_cast<int>(round(set_seconds));
    
        this->hours_ = total_seconds / 3600;
        total_seconds = total_seconds % 3600;

        this->minutes_  = total_seconds / 60;
        total_seconds = total_seconds % 60;

        this->seconds_ = total_seconds;

    }


    TimeSpan TimeSpan::operator+(TimeSpan const& other_time) {
        int this_total_seconds = (hours_ * 3600) + (minutes_ * 60) + seconds_;
        int other_total_seconds = (other_time.hours_ * 3600) + (other_time.minutes_ * 60) + other_time.seconds_;

        int total_seconds = this_total_seconds + other_total_seconds;


        int new_hours = total_seconds / 3600;
        total_seconds = total_seconds % 3600;

        int new_minutes = total_seconds / 60;
        total_seconds = total_seconds % 60;

        int new_seconds = total_seconds;


        return TimeSpan(new_hours, new_minutes, new_seconds);

        

    }
    TimeSpan TimeSpan::operator-(TimeSpan const& other_time){
        int this_total_seconds = (hours_ * 3600) + (minutes_ * 60) + seconds_;
        int other_total_seconds = (other_time.hours_ * 3600) + (other_time.minutes_ * 60) + other_time.seconds_;

        int total_seconds = this_total_seconds - other_total_seconds;


        int new_hours = total_seconds / 3600;
        total_seconds = total_seconds % 3600;

        int new_minutes = total_seconds / 60;
        total_seconds = total_seconds % 60;

        int new_seconds = total_seconds;


        return TimeSpan(new_hours, new_minutes, new_seconds);

    }

    TimeSpan TimeSpan::operator+=(TimeSpan const& other_time){
        int this_total_seconds = (hours_ * 3600) + (minutes_ * 60) + seconds_;
        int other_total_seconds = (other_time.hours_ * 3600) + (other_time.minutes_ * 60) + other_time.seconds_;

        
        this_total_seconds += other_total_seconds;

        hours_ = this_total_seconds / 3600;
        this_total_seconds %= 3600;
        minutes_ = this_total_seconds / 60;
        seconds_ = this_total_seconds % 60;


        return *this;
    }





    TimeSpan TimeSpan::operator-=(TimeSpan const& other_time){
        int this_total_seconds = (hours_ * 3600) + (minutes_ * 60) + seconds_;
        int other_total_seconds = (other_time.hours_ * 3600) + (other_time.minutes_ * 60) + other_time.seconds_;

        
        this_total_seconds -= other_total_seconds;

        hours_ = this_total_seconds / 3600;
        this_total_seconds %= 3600;
        minutes_ = this_total_seconds / 60;
        seconds_ = this_total_seconds % 60;


        return *this;
    }


    TimeSpan TimeSpan::operator-() const {
        return TimeSpan(-hours_, -minutes_, -seconds_);
    }



    bool TimeSpan::operator!=(const TimeSpan& other_time) const {
        int this_total_seconds = (hours_ * 3600) + (minutes_ * 60) + seconds_;
        int other_total_seconds = (other_time.hours_ * 3600) + (other_time.minutes_ * 60) + other_time.seconds_;
        if(this_total_seconds != other_total_seconds) 
        {
            return true;
        }
        
        return false;
    }
    bool TimeSpan::operator==(const TimeSpan& other_time) const {
        int this_total_seconds = (hours_ * 3600) + (minutes_ * 60) + seconds_;
        int other_total_seconds = (other_time.hours_ * 3600) + (other_time.minutes_ * 60) + other_time.seconds_;
        if(this_total_seconds == other_total_seconds) 
        {
            return true;
        }
        
        return false;



    }
    bool TimeSpan::operator<=(const TimeSpan& other_time) const {
        int this_total_seconds = (hours_ * 3600) + (minutes_ * 60) + seconds_;
        int other_total_seconds = (other_time.hours_ * 3600) + (other_time.minutes_ * 60) + other_time.seconds_;
        if(this_total_seconds <= other_total_seconds) 
        {
            return true;
        }
        
        return false;


    }
    bool TimeSpan::operator>=(const TimeSpan& other_time) const {
        int this_total_seconds = (hours_ * 3600) + (minutes_ * 60) + seconds_;
        int other_total_seconds = (other_time.hours_ * 3600) + (other_time.minutes_ * 60) + other_time.seconds_;
        if(this_total_seconds >= other_total_seconds) 
        {
            return true;
        }
        
        return false;




    }
    bool TimeSpan::operator<(const TimeSpan& other_time) const {
        int this_total_seconds = (hours_ * 3600) + (minutes_ * 60) + seconds_;
        int other_total_seconds = (other_time.hours_ * 3600) + (other_time.minutes_ * 60) + other_time.seconds_;
        if(this_total_seconds < other_total_seconds) 
        {
            return true;
        }
        
        return false;


    }
    bool TimeSpan::operator>(const TimeSpan& other_time) const {
        int this_total_seconds = (hours_ * 3600) + (minutes_ * 60) + seconds_;
        int other_total_seconds = (other_time.hours_ * 3600) + (other_time.minutes_ * 60) + other_time.seconds_;
        if(this_total_seconds > other_total_seconds) 
        {
            return true;
        }
        
        return false;
    }









ostream& operator<<(ostream& output, const TimeSpan& time){

    output << "Hours: " << time.hours() << ", Minutes: " << time.minutes() << ", Seconds: " << time.seconds() << " ";
    return output;
}



istream& operator>>(istream& input, TimeSpan& time){
    int hours, minutes, seconds;

    if(input >> hours >> minutes >> seconds)
    {
        time.set_time(hours, minutes, seconds);
    }
    else 
    {
        input.clear();
        time.set_time(0,0,0);
    }


    return input;

}























