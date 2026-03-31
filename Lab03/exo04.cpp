/******************************************************************************
Solve this problem in an object-oriented way.
Design a base class Appliance with name, and then design a derived class Fan with an extra data member speed.
After reading the fan name and its speed, create a Fan object and output the name and speed.
You must use the inheritance relationship between the base class and the derived class in your program.

The input contains one line with a string name and an integer speed.
Output name speed separated by one space.
Sample Input 
DeskFan 3
Sample Output
DeskFan 3
*******************************************************************************/
#include <iostream>
#include <string> 
using namespace std; 
class Appliance{
    public:
    string name;
};

class Fan: public Appliance{
    public:
    int speed;
    void input(){
        cin >> name >> speed;
    }
    void output(){
        cout << name << " " << speed;
    }
};

int main()
{
    
    Fan fan;
    fan.input();
    fan.output();

    return 0;
}

