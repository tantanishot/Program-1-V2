#include <iostream>
#include "time_span.h"
using namespace std;

// Helper function to check if TimeSpan values match the expected hours, minutes, and seconds
bool CheckValues(TimeSpan time, int hours, int minutes, int seconds) {
    return (time.hours() == hours) && (time.minutes() == minutes) && (time.seconds() == seconds);
}

// Test case: TimeSpan with zero values
bool TestZeros() {
    TimeSpan ts(0, 0, 0);
    return CheckValues(ts, 0, 0, 0);
}

// Test case: TimeSpan with fractional seconds
bool TestFloatSeconds() {
    TimeSpan ts(127.86);
    return CheckValues(ts, 0, 2, 8);
}

// Test case: TimeSpan with negative minutes
bool TestNegativeMinute() {
    TimeSpan ts(8, -23, 0);
    return CheckValues(ts, 7, 37, 0);
}

// Test case: TimeSpan with negative hours
bool TestNegativeHour() {
    TimeSpan ts(-3, 73, 2);
    return CheckValues(ts, -1, -46, -58);
}

// Test case: Addition of multiple TimeSpan objects
bool TestAdd() {
    TimeSpan ts1, ts2(5), ts3(7, 0), ts4(4, 0, 0);
    TimeSpan add_it_up = ts1 + ts2 + ts3 + ts4;
    return CheckValues(add_it_up, 4, 7, 5);
}

// Test case: In-place addition
bool TestAddInPlace() {
    TimeSpan ts1(5, 6, 7);
    TimeSpan ts2(1, 1, 1);
    ts1 += ts2;
    return CheckValues(ts1, 6, 7, 8) && CheckValues(ts2, 1, 1, 1);
}

// Test case: Subtraction of TimeSpan objects
bool TestSubtract() {
    TimeSpan ts1(5, 6, 7);
    TimeSpan ts2(1, 1, 1);
    TimeSpan result = ts1 - ts2;
    return CheckValues(result, 4, 5, 6);
}

// Test case: In-place subtraction
bool TestSubtractInPlace() {
    TimeSpan ts1(5, 6, 7);
    TimeSpan ts2(1, 1, 1);
    ts1 -= ts2;
    return CheckValues(ts1, 4, 5, 6) && CheckValues(ts2, 1, 1, 1);
}

// Test case: Unary negation
bool TestUnaryNegation() {
    TimeSpan ts(1, 2, 3);
    TimeSpan negated = -ts;
    return CheckValues(negated, -1, -2, -3);
}

// Test case: Comparison operators
bool TestComparisonOperators() {
    TimeSpan ts1(1, 2, 3);
    TimeSpan ts2(1, 2, 3);
    TimeSpan ts3(0, 59, 59);
    
    return (ts1 == ts2) &&
           (ts1 != ts3) &&
           (ts3 < ts1) &&
           (ts3 <= ts1) &&
           (ts1 > ts3) &&
           (ts1 >= ts3);
}

// Test case: Set and get time
bool TestSetTime() {
    TimeSpan ts;
    ts.set_time(3, 15, 45);
    return CheckValues(ts, 3, 15, 45);
}

// Test case: Set individual components
bool TestSetIndividualComponents() {
    TimeSpan ts;
    ts.set_hours(2);
    ts.set_minutes(30);
    ts.set_seconds(40);
    return CheckValues(ts, 2, 30, 40);
}

int main() {
    cout << "Testing TimeSpan Class" << endl;
    if (!TestZeros()) cout << "Failed: TestZeros" << endl;
    if (!TestFloatSeconds()) cout << "Failed: TestFloatSeconds" << endl;
    if (!TestNegativeMinute()) cout << "Failed: TestNegativeMinute" << endl;
    if (!TestNegativeHour()) cout << "Failed: TestNegativeHour" << endl;
    if (!TestAdd()) cout << "Failed: TestAdd" << endl;
    if (!TestAddInPlace()) cout << "Failed: TestAddInPlace" << endl;
    if (!TestSubtract()) cout << "Failed: TestSubtract" << endl;
    if (!TestSubtractInPlace()) cout << "Failed: TestSubtractInPlace" << endl;
    if (!TestUnaryNegation()) cout << "Failed: TestUnaryNegation" << endl;
    if (!TestComparisonOperators()) cout << "Failed: TestComparisonOperators" << endl;
    if (!TestSetTime()) cout << "Failed: TestSetTime" << endl;
    if (!TestSetIndividualComponents()) cout << "Failed: TestSetIndividualComponents" << endl;
    cout << "Testing Complete" << endl;
}
