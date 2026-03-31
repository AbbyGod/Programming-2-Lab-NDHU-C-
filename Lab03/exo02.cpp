/******************************************************************************
Create a class to store two scores, and create an object to handle the correction process. 
You must use reference parameters so a member function can adjust these two values, then output  
the final result.This problem should be solved in an object-oriented way instead of only using
ordinary functions and standalone variables.
The input contains one line with two integers a b.Output the two integers in sorted order,
separated by one space. Sample Input 9 12  Sample Output 12 9
*******************************************************************************/
#include <iostream>
using namespace std;
class Order{
    public:
    int a, b;
    void input(){
    cin >> a >> b;    
    }
    
    
   void swap ( int& x, int& y){
        int temp = x;
        x = y;
        y = temp;
         }
    
    
    void output(){
        if (a > b){
            swap(a,b);
        }
        cout << a << " " << b;
    }
    
    
};

int main()
{
    Order numbers;
    numbers.input();
    numbers.output();

    return 0;
}

