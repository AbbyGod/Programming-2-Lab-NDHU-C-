/******************************************************************************
Create a class to store temperature data, and create an object to handle input and update. 
You must use a member function with reference parameters so the value inside the object can be
modified directly, then output the updated result.Use the ideas of class, object, 
and reference to solve this problem. 。The input contains one line with two integers x k.
。Output the updated integer.    Sample Input: 13 5 Sample Output 18
*******************************************************************************/
#include <iostream>
using namespace std;
class temperature {
    public:
    int a, b;
    void input(){
        cin >> a >> b;
    }
    void update (int& x, int& y){
        int result = x + y;
    }
    void output(){
        cout << a + b;
    }
};

int main()
{
    temperature Temp;
    Temp.input();
    Temp.output();

    return 0;
}
