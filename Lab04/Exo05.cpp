/******************************************************************************
The final problem continues the triangle object from the previous problem. Design a class CoverageTriangle
to represent a triangle formed by three ordered points A, B, and C, and solve the problem in an object-oriented way.
You must use classes, objects, and member functions. It is recommended that CoverageTriangle stores three Point object
internally and computes the area through a member function. Do not simply place the formula directly in main.
Given three points A(x1, y1), B(x2, y2), and C(x3, y3), the points are provided in the specified order, 
and valid tests do not involve self-overlapping situations. Create the triangle object and compute its area. 
If the three points are collinear, the area is 0.00. Print the result with exactly two digits after the decimal point.
Input consists of one line containing six integers x1 y1 x2 y2 x3 y3.
Output one line in the format Area: s, where s is the area of the triangle printed with exactly two digits after the decimal point.
Sample Input 
0 0 4 0 0 3
Sample Output 
Area: 6.00
*******************************************************************************/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Point {
public:
    int x, y;
    Point(int px, int py) : x(px), y(py) {}
};

class CoverageTriangle {
private:
    Point A, B, C;

public:
    CoverageTriangle(Point a, Point b, Point c) : A(a), B(b), C(c) {}

    double area() const {
        long long cross = (long long)(B.x - A.x) * (C.y - A.y)
                        - (long long)(B.y - A.y) * (C.x - A.x);
        return abs(cross) / 2.0;
    }
};

int main() {
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    CoverageTriangle tri(Point(x1, y1), Point(x2, y2), Point(x3, y3));
    cout << fixed << setprecision(2);
    cout << "Area: " << tri.area() << endl;

    return 0;
}


