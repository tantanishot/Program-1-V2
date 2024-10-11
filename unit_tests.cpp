#include <iostream>
#include <sstream>
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

// Edge case: Handling very large values
bool TestLargeValues() {
    TimeSpan ts(1000000); // 1,000,000 seconds
    return CheckValues(ts, 277, 46, 40); // 277 hours, 46 minutes, 40 seconds
}

// Edge case: Handling very small fractional seconds (near zero)
bool TestSmallFractionalSeconds() {
    TimeSpan ts(0.001);
    return CheckValues(ts, 0, 0, 0); // Should round down to 0 seconds
}

// Edge case: Handling negative fractional seconds
bool TestNegativeFractionalSeconds() {
    TimeSpan ts(-127.86);
    return CheckValues(ts, -0, -2, -8); // -2 minutes, -8 seconds
}

// Edge case: Crossing minute boundaries
bool TestCrossMinuteBoundary() {
    TimeSpan ts(59.5); // 59.5 seconds should round up to 1 min
    return CheckValues(ts, 0, 1, 0); // Should round up to 1 minute
}

// Edge case: TimeSpan with a very large negative value
bool TestLargeNegativeValues() {
    TimeSpan ts(-1000000); // -1,000,000 seconds
    return CheckValues(ts, -277, -46, -40); // -277 hours, -46 minutes, -40 seconds
}

// Edge case: Input stream operator (>>) with valid input
bool TestInputStreamValid() {
    TimeSpan ts;
    stringstream ss("2 45 30"); // 2 hours, 45 minutes, 30 seconds
    ss >> ts;
    return CheckValues(ts, 2, 45, 30); // Should be 2 hours, 45 minutes, 30 seconds
}


// Edge case: TimeSpan with zero seconds
bool TestZeroSeconds() {
    TimeSpan ts(0);
    return CheckValues(ts, 0, 0, 0);
}

// Edge case: TimeSpan with a combination of negative and positive values
bool TestMixedPositiveNegative() {
    TimeSpan ts(1, -30, 45); // 1 hour, -30 minutes, 45 seconds
    return CheckValues(ts, 0, 30, 45); // Should correctly adjust to 0 hours, 29 minutes, 45 seconds
}


//Test Case: Checks if the output is the expected format
bool TestOutputCheck() {
    TimeSpan ts(59, 59, 59);
    string compare = ("Hours: 59, Minutes: 59, Seconds: 59 ");
    ostringstream output_test;
    output_test << ts;
    return (compare == output_test.str());
}

//Edge Case: Checks for smaller granulated floats passed in 
bool TestFloats1() {
    TimeSpan ts(2.6, 3, -10);
    cout << ts << endl;
    return CheckValues(ts, 2, 38, 50);
}


bool TestFloats2() {
    TimeSpan ts(1.61, -1.76);
    cout << ts << endl;
    return CheckValues(ts, 0, 1, 35);


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
    if (!TestLargeValues()) cout << "Failed: TestLargeValues" << endl;
    if (!TestSmallFractionalSeconds()) cout << "Failed: TestSmallFractionalSeconds" << endl;
    if (!TestNegativeFractionalSeconds()) cout << "Failed: TestNegativeFractionalSeconds" << endl;
    if (!TestCrossMinuteBoundary()) cout << "Failed: TestCrossMinuteBoundary" << endl;
    if (!TestLargeNegativeValues()) cout << "Failed: TestLargeNegativeValues" << endl;
    if (!TestInputStreamValid()) cout << "Failed: TestInputStreamValid" << endl;
    if (!TestZeroSeconds()) cout << "Failed: TestZeroSeconds" << endl;
    if (!TestMixedPositiveNegative()) cout << "Failed: TestMixedPositiveNegative" << endl;
    if (!TestOutputCheck()) cout << "Failed: TestOutputCheck" << endl;
    if (!TestFloats1()) cout << "Failed: TestFloats1" << endl;
    if (!TestFloats2()) cout << "Failed: TestFloats2" << endl;
    cout << "Testing Complete" << endl;
}
