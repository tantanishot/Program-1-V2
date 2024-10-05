
#include <iostream> 
#ifndef VENDING_BANK_H_
#define VENDING_BANK_H_
#include <string>
using namespace std;



class TimeSpan {



    public: 
    TimeSpan(int hours, int minutes, int seconds);
    TimeSpan(int minutes, int seconds);
    TimeSpan(int seconds);
    TimeSpan();



    //getters
    int hours() const;
    int minutes() const;
    int seconds() const;


 

    
    //setters
    void set_time(int hours, int minutes, int seconds);



    //op overloads Add, Subtract
    TimeSpan operator+(TimeSpan const& other_time);
    TimeSpan operator-(TimeSpan const& other_time);
    TimeSpan operator+=(const TimeSpan& other_time);
    TimeSpan operator-=(const TimeSpan& other_time);

     //opoverload unary neg


    //opoverload comparisons
    bool operator!=(const TimeSpan& other_time) const;
    bool operator==(const TimeSpan& other_time) const;
    bool operator<=(const TimeSpan& other_time) const;
    bool operator>=(const TimeSpan& other_time) const;
    bool operator<(const TimeSpan& other_time) const;
    bool operator>(const TimeSpan& other_time) const;

    //opoverload cout cin
    friend ostream& operator<<(ostream& output, const TimeSpan& time);
    friend ostream& operator>>(istream& input, const TimeSpan& time);
   
    




    private:

    int hours_;
    int minutes_;
    int seconds_;











};
#endif