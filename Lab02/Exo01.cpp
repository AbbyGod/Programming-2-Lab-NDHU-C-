/******************************************************************************
Design a NumberBox class. Use a constructor to receive an integer and store it in a member variable.
Then output the value stored in the object. This problem practices the most basic constructor initialization.
Sample Input 1 
42
Sample Output 1
Value: 42
*******************************************************************************/
#include <iostream>
#include <string>
using namespace std;

class number{
    public:
    int n;
    number(int N){
       n = N;
    }
};

int main()
{ 
    int input;
    cin >> input;
    number value(input);
    std::cout<< "Value: " << value.n ;

    return 0;
}