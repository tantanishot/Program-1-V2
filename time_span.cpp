
#include <iostream>
#include <string>
#include "time_span.h"
#include <cmath>
using namespace std;


int main();


    TimeSpan::TimeSpan(double hours, double minutes, double seconds) {
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

    TimeSpan::TimeSpan(double minutes, double seconds) {
        int total_seconds = 0;
        total_seconds += minutes * 60;
        total_seconds += seconds;

        this->hours_ = total_seconds / 3600;
        total_seconds = total_seconds % 3600;

        this->minutes_  = total_seconds / 60;
        total_seconds = total_seconds % 60;

        this->seconds_ = total_seconds;

    }


    TimeSpan::TimeSpan(double seconds) {
        int total_seconds = seconds;
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
        int total_seconds = 0;
        total_seconds += new_hours * 3600;
        total_seconds += new_minutes * 60;
        total_seconds += new_seconds;

        //set times
        this->hours_ = total_seconds / 3600;
        total_seconds = total_seconds % 3600;

        this->minutes_  = total_seconds / 60;
        total_seconds = total_seconds % 60;

        this->seconds_ = total_seconds;
    }

    void TimeSpan::set_hours(double new_hours) { 
        this->hours_ = 0;
        int total_seconds = 0;
        total_seconds += hours() * 3600;
        total_seconds += minutes() * 60;
        total_seconds += seconds();

        total_seconds += new_hours * 3600;


        this->hours_ = total_seconds / 3600;
        total_seconds = total_seconds % 3600;

        this->minutes_  = total_seconds / 60;
        total_seconds = total_seconds % 60;

        this->seconds_ = total_seconds;


    }
    void TimeSpan::set_minutes(double new_minutes) {\
        this->minutes_ = 0;
        int total_seconds = 0;
        total_seconds += hours() * 3600;
        total_seconds += minutes() * 60;
        total_seconds += seconds();

        total_seconds += new_minutes * 60;


        this->hours_ = total_seconds / 3600;
        total_seconds = total_seconds % 3600;

        this->minutes_  = total_seconds / 60;
        total_seconds = total_seconds % 60;

        this->seconds_ = total_seconds;


    }
    void TimeSpan::set_seconds(double new_seconds) {
        this->seconds_ = 0;
        int total_seconds = 0;
        total_seconds += hours() * 3600;
        total_seconds += minutes() * 60;
        total_seconds += seconds();

        total_seconds += new_seconds;


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










int main() {
    // Test constructors
    TimeSpan ts1(1, 30, 45);    // 1 hour, 30 minutes, 45 seconds
    TimeSpan ts2(90, 30);       // 90 minutes, 30 seconds
    TimeSpan ts3(3600);         // 3600 seconds (1 hour)
    TimeSpan ts4;               // Default constructor (0 hours, 0 minutes, 0 seconds)

    cout << "Testing constructors:\n";
    cout << "ts1: " << ts1;
    cout << "ts2: " << ts2;
    cout << "ts3: " << ts3;
    cout << "ts4 (default): " << ts4;
    cout << endl;

    // Test + operator
    TimeSpan ts_add = ts1 + ts2; // Adding ts1 and ts2
    cout << "Testing + operator (ts1 + ts2):\n";
    cout << "ts1: " << ts1;
    cout << "ts2: " << ts2;
    cout << "Result (ts1 + ts2): " << ts_add << endl;


    TimeSpan ts_sub = ts1 - ts2; // Subtracting ts2 from ts1
    cout << "Testing - operator (ts1 - ts2):\n";
    cout << "ts1: " << ts1;
    cout << "ts2: " << ts2;
    cout << "Result (ts1 - ts2): " << ts_sub << endl;




    cout << "Testing setters (ts1):\n";
    ts1.set_hours(2);            // Set hours to 2
    ts1.set_minutes(15);         // Set minutes to 15
    ts1.set_seconds(50);         // Set seconds to 50
    cout << "After setting ts1 to 2 hours, 15 minutes, and 50 seconds: " << ts1;




    // Test set_time
    cout << "Testing set_time (ts2):\n";
    ts2.set_time(5, 45, 25);     // Set ts2 to 5 hours, 45 minutes, and 25 seconds
    cout << "After setting ts2 to 5 hours, 45 minutes, and 25 seconds: " << ts2;


    //----
        // Test input operator >>
    cout << "\nEnter time (hours, minutes, seconds) for ts5: ";
    TimeSpan ts5;
    cin >> ts5;
    cout << "You entered ts5: " << ts5;

    // Testing += operator
    cout << "\nTesting += operator (ts1 += ts2):" << endl;
    ts1 += ts2;
    cout << "Result (ts1 += ts2): " << ts1;

    // Testing -= operator
    cout << "\nTesting -= operator (ts1 -= ts2):" << endl;
    ts1 -= ts2;
    cout << "Result (ts1 -= ts2): " << ts1;

    // Testing Comparison Operators
    cout << "\nTesting comparison operators:" << endl;
    cout << "ts1: " << ts1;
    cout << "ts2: " << ts2;

    if (ts1 == ts2) {
        cout << "ts1 is equal to ts2" << endl;
    } else {
        cout << "ts1 is not equal to ts2" << endl;
    }

    if (ts1 != ts2) {
        cout << "ts1 is not equal to ts2" << endl;
    }

    if (ts1 < ts2) {
        cout << "ts1 is less than ts2" << endl;
    }

    if (ts1 <= ts2) {
        cout << "ts1 is less than or equal to ts2" << endl;
    }

    if (ts1 > ts2) {
        cout << "ts1 is greater than ts2" << endl;
    }

    if (ts1 >= ts2) {
        cout << "ts1 is greater than or equal to ts2" << endl;
    }

    // Testing Setters and Getters
    cout << "\nTesting Setters and Getters:" << endl;
    ts1.set_time(3, 15, 30);
    cout << "After setting ts1 to 3 hours, 15 minutes, 30 seconds: " << ts1;

    ts1.set_hours(5);
    cout << "After setting ts1 hours to 5: " << ts1;

    ts1.set_minutes(20);
    cout << "After setting ts1 minutes to 20: " << ts1;

    ts1.set_seconds(50);
    cout << "After setting ts1 seconds to 50: " << ts1;

    


    
    return 0;

}














