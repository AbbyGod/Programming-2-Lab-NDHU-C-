/******************************************************************************
Design a class AxisReading to represent a one-dimensional position on a straight hallway. You must solve this problem using object-oriented programming.
Create class objects. The class should store at least one integer coordinate value and provide member functions to access the value and compute the absolute
difference between two readings. Do not solve the whole problem using only ordinary variables.
Given two integers a and b, create two AxisReading objects and output their coordinates and the distance between them.
Input consists of one line containing two integers a and b.
Output three lines. The first line prints Sensor A: followed by the coordinate of the first object. 
The second line prints Sensor B: followed by the coordinate of the second object. The third line prints Distance: followed by the absolute difference.
Sample Input 1 
3 10
Sample Output 
Sensor A: 3
Sensor B: 10
Distance: 7

*******************************************************************************/
#include <iostream>
#include <cmath>
using namespace std;

class AxisReading {
private:
    int coordinate;

public:
    AxisReading(int val) : coordinate(val) {}

    int getValue() const {
        return coordinate;
    }

    int distanceTo(const AxisReading& other) const {
        return abs(coordinate - other.coordinate);
    }
};

int main() {
    int a, b;
    cin >> a >> b;

    AxisReading sensorA(a);
    AxisReading sensorB(b);

    cout << "Sensor A: " << sensorA.getValue() << endl;
    cout << "Sensor B: " << sensorB.getValue() << endl;
    cout << "Distance: " << sensorA.distanceTo(sensorB) << endl;

    return 0;
}





