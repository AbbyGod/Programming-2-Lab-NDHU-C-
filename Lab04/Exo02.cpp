/******************************************************************************
You must create a class and an object. The MapPoint class should store at least two integer members x and y and provide member functions
to print the point information. Do not simply use two ordinary integer variables to print the answer directly.
Given integers x and y, create a MapPoint object and output its coordinates and the value of x+y. The purpose of this problem
is to check whether you can encapsulate multiple data fields inside one object.
Input consists of one line containing two integers x and y.
Output two lines. The first line prints Point: (x, y). The second line prints Sum: followed by x+y.
Sample Input 
4 -7
Sample Output
Point: (4, -7)
Sum: -3

*******************************************************************************/
#include <iostream>
using namespace std;

class MapPoint {
private:
    int x, y;

public:
    MapPoint(int px, int py) : x(px), y(py) {}

    void printPoint() const {
        cout << "Point: (" << x << ", " << y << ")" << endl;
    }

    void printSum() const {
        cout << "Sum: " << x + y << endl;
    }
};

int main() {
    int x, y;
    cin >> x >> y;

    MapPoint p(x, y);
    p.printPoint();
    p.printSum();

    return 0;
}
    
