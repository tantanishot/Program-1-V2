
#include <iostream>
#include <string>
#include "time_span.h"
#include <cmath>
using namespace std;




    TimeSpan::TimeSpan(double hours, double minutes, double seconds) {
        hours = round(hours);
        minutes = round(minutes);
        seconds = round(seconds);

        int total_seconds = static_cast<int>(hours * 3600 + minutes * 60 + seconds);

        //set times
        this->hours_ = total_seconds / 3600;
        total_seconds = total_seconds % 3600;

        this->minutes_  = total_seconds / 60;
        total_seconds = total_seconds % 60;

        this->seconds_ = total_seconds;
    }

    TimeSpan::TimeSpan(double minutes, double seconds) {
        minutes = round(minutes);
        seconds = round(seconds);

        int total_seconds = static_cast<int>(minutes * 60 + seconds);

        this->hours_ = total_seconds / 3600;
        total_seconds = total_seconds % 3600;

        this->minutes_  = total_seconds / 60;
        total_seconds = total_seconds % 60;

        this->seconds_ = total_seconds;

    }


    TimeSpan::TimeSpan(double seconds) {
        int total_seconds = round(seconds);

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
        new_hours = round(new_hours);
        new_minutes = round(new_minutes);
        new_seconds = round(new_seconds);
        
        
        int total_seconds = static_cast<int>(new_hours * 3600 + new_minutes * 60 + new_seconds);
        //set times
        this->hours_ = total_seconds / 3600;
        total_seconds = total_seconds % 3600;

        this->minutes_  = total_seconds / 60;
        total_seconds = total_seconds % 60;

        this->seconds_ = total_seconds;
    }

    void TimeSpan::set_hours(double new_hours) { 
        this->hours_ = 0;
        new_hours = round(new_hours);
        int total_seconds = static_cast<int>(new_hours * 3600 + minutes() * 60 + seconds());

        this->hours_ = total_seconds / 3600;
        total_seconds = total_seconds % 3600;

        this->minutes_  = total_seconds / 60;
        total_seconds = total_seconds % 60;

        this->seconds_ = total_seconds;


    }
    void TimeSpan::set_minutes(double new_minutes) {\
        this->minutes_ = 0;
        new_minutes = round(new_minutes);

        int total_seconds = static_cast<int>(hours() * 3600 + new_minutes * 60 + seconds());
        total_seconds += new_minutes * 60;


        this->hours_ = total_seconds / 3600;
        total_seconds = total_seconds % 3600;

        this->minutes_  = total_seconds / 60;
        total_seconds = total_seconds % 60;

        this->seconds_ = total_seconds;


    }
    void TimeSpan::set_seconds(double new_seconds) {
        this->seconds_ = 0;
        int total_seconds = round(new_seconds);
    
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
    output << time.hours() << " Hours, " << time.minutes() << " Minutes, " << time.seconds() << " Seconds" << endl;
    return output;
}



istream& operator>>(istream& input, TimeSpan& time){
    int hours, minutes, seconds;

    input >> hours >> minutes >> seconds;

    time.set_time(hours, minutes, seconds);

    return input;

}





















