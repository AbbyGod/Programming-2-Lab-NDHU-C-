/******************************************************************************
Solve this problem in an object-oriented way.
Design a base class Person with name, and then design a derived class Teacher with an extra data member subject.
After reading the teacher name and subject, create a Teacher object and output the name and subject.
This problem requires you to complete the task using classes, objects, and basic inheritance syntax.

Input
The input contains one line with two strings name and subject.
Amy Physics
Sample Output 
Amy Physics
*******************************************************************************/
#include <iostream>
#include <string> 
using namespace std; 
class Person{
    public:
    string name;
};

class Teacher: public Person{
    public:
    string subject;
    void input(){
        cin >> name >> subject;
    }
    void output(){
        cout << name << " " << subject;
    }
};

int main()
{
    
    Teacher teacher;
    teacher.input();
    teacher.output();

    return 0;
}
