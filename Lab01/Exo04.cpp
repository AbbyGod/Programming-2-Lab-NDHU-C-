/******************************************************************************
Design a simpleCounterclass concept to represent a counter. The initial value is 0.
Then you will be given several operations. Each operation is eitherINC(increase by 1) orDEC(decrease by 1). Output the final value.
This problem is good practice for letting an object store its own state and change with operations.

The first line contains an integerN, the number of operations.
The nextNlines each contain a string, eitherINCorDEC.

Output one line in the formatValue: X, whereXis the final counter value.
*******************************************************************************/
#include <iostream>
#include <string>
using namespace std;

class Counter{
    public:
    int n;
    string operation;
    int result;
    Counter () {
        result = 0;
    }
    void total(){
        if (operation == "INC") result++;
        if (operation == "DEC") result--;
    }
};

int main()
{
    Counter counter;
    std::cin >> counter.n;
    for (int i = 0; i < counter.n ; i++){
        std::cin >> counter.operation;
        counter.total();
    }
    std::cout << "Value: " << counter.result;

    return 0;
} 