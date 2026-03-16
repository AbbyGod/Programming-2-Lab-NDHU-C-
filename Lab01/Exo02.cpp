/******************************************************************************
Design a simplePlayerclass concept to represent the state of a music player. The initial state is STOP.
Then you will be given several operations, each of which is eitherPLAYorSTOP. Output the final state.
This problem is good practice for storing an object'sstateinside a class.

The first line contains an integerN, the number of operations.
The nextNlines each contain a string, eitherPLAYorSTOP.

Output one line in the formatState: X, whereXis the final state.

*******************************************************************************/
#include <iostream>
#include<string>
using namespace std;

class Player{
  public:
  int n;
  string operation;
};

int main()
{
    Player p;
    cin >> p.n;
    int i;
    for (i > 0; i < p.n; i++ ){
        cin >> p.operation;
    }
std::cout << "State: " << p.operation << std::endl;
    return 0;
}