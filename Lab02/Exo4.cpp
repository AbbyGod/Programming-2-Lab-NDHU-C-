/******************************************************************************
Design a Report class. The constructor receives two scores and stores them.
A member function outputs their integer average, and the destructor always prints Destroy report.
The input contains one line with two integers a b.
Sample Input: 80 90
Sample Output
Average: 85
Destroy report
*******************************************************************************/
#include <iostream>
#include <string>
using namespace std;
class Report{
    public:
    int a, b;
    Report (int x, int y){
        a = x;
        b = y;
    }
    void average(){
        cout << "Average: " << (a + b)/2 << endl;
    }
    ~Report(){
        cout << "Destroy report" << endl;
    }
};
int main()
{
    int a, b;
    cin >> a >> b;
    Report report(a, b);
    report.average();
   

    return 0;
}