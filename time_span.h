
#include <iostream> 
#ifndef VENDING_BANK_H_
#define VENDING_BANK_H_
#include <string>
using namespace std;



class TimeSpan {



    public: 
    TimeSpan(double hours, double minutes, double seconds);
    TimeSpan(double minutes, double seconds);
    TimeSpan(double seconds);
    TimeSpan();



    //getters
    int hours() const;
    int minutes() const;
    int seconds() const;


 

    
    //setters
    void set_time(double new_hours, double new_minutes, double new_seconds);
    void set_hours(double new_hours);
    void set_minutes(double new_minutes);
    void set_seconds(double new_seconds);


    //op overloads Add, Subtract
    TimeSpan operator+(TimeSpan const& other_time);
    TimeSpan operator-(TimeSpan const& other_time);
    TimeSpan operator+=(const TimeSpan& other_time);
    TimeSpan operator-=(const TimeSpan& other_time);

     //opoverload unary neg
    TimeSpan operator-() const;


    //opoverload comparisons
    bool operator!=(const TimeSpan& other_time) const;
    bool operator==(const TimeSpan& other_time) const;
    bool operator<=(const TimeSpan& other_time) const;
    bool operator>=(const TimeSpan& other_time) const;
    bool operator<(const TimeSpan& other_time) const;
    bool operator>(const TimeSpan& other_time) const;

    //opoverload cout cin

    friend ostream& operator>>(ostream& input, const TimeSpan& time);
    friend istream& operator<<(istream& input, TimeSpan& time);
   
    




    private:

    int hours_;
    int minutes_;
    int seconds_;











};
#endif