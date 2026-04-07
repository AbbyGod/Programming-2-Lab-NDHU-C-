/******************************************************************************
Now combine single points into a shape. Design a class SurveyTriangle to represent a triangle formed by three ordered points A, B, and C,
and solve the problem in an object-oriented way.
You must use classes and objects. It is recommended to define a Point class first, 
then define a SurveyTriangle class so that a triangle object stores three point objects internally. 
Do not solve this problem using only nine numbers and a few ordinary functions.
Given three points A(x1, y1), B(x2, y2), and C(x3, y3), create a SurveyTriangle object and determine whether these three points can form a valid triangle.
If the three points are collinear, print Invalid; otherwise print Valid.
Input consists of one line containing six integers x1 y1 x2 y2 x3 y3.
If the three points form a valid triangle, print Valid. Otherwise print Invalid.
Sample Input 
0 0 4 0 0 3
Sample Output 
Valid
*******************************************************************************/
#include <iostream>
using namespace std;

class Point {
public:
    int x, y;
    Point(int px, int py) : x(px), y(py) {}
};

class SurveyTriangle {
private:
    Point A, B, C;

public:
    SurveyTriangle(Point a, Point b, Point c) : A(a), B(b), C(c) {}

    bool isValid() const {
        // Cross product of AB and AC; if 0, points are collinear
        int cross = (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
        return cross != 0;
    }
};

int main() {
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    SurveyTriangle tri(Point(x1, y1), Point(x2, y2), Point(x3, y3));
    cout << (tri.isValid() ? "Valid" : "Invalid") << endl;

    return 0;
}