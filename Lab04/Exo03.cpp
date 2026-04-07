/******************************************************************************
In map surveying, the distance between two observation points is one of the most fundamental quantities.
Design a class SurveyPoint to represent a point on the plane and solve this problem in an object-oriented way.
You must create a class and objects, and the class should store at least x and y.
Provide a member function to compute the Euclidean distance between two SurveyPoint objects. Do not solve the entire problem using only an ordinary function and four integers.
Given two points A(x1, y1) and B(x2, y2), create two SurveyPoint objects and output the distance between them.
The answer must be printed with exactly two digits after the decimal point.
Input consists of one line containing four integers x1 y1 x2 y2.
Output one line in the format Distance: d, where d is the distance between the two points printed with exactly two digits after the decimal point.
Sample Input 
0 0 3 4
Sample Output 
Distance: 5.00
*******************************************************************************/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class SurveyPoint {
private:
    int x, y;

public:
    SurveyPoint(int px, int py) : x(px), y(py) {}

    double distanceTo(const SurveyPoint& other) const {
        int dx = x - other.x;
        int dy = y - other.y;
        return sqrt(dx*dx + dy*dy);
    }
};

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    SurveyPoint A(x1, y1), B(x2, y2);
    cout << fixed << setprecision(2);
    cout << "Distance: " << A.distanceTo(B) << endl;

    return 0;
}

