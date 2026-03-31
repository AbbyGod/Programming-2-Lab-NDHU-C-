/******************************************************************************
Create one object whose constructor prints Construct name, and then print Use name.
The object exists inside an inner block, so before printing Done, the destructor will be called and print Destruct name.
The input contains one line with one string name without spaces.
Sample Input 1: Lamp
Sample Output 1:
Construct Lamp
Use Lamp
Destruct Lamp
Done

*******************************************************************************/
#include <iostream>
#include <string>
using namespace std;
class Object {
public:
	string name;
	Object (string n) {
		name = n;
		cout << "Construct "<< name <<endl;
	}
	~Object() {
		cout << "Destruct "<< name <<endl;
	}
};

int main()
{
	string n;
	cin >> n;
    {
        Object obj(n);
        cout << "Use " << obj.name << endl;
    }
    
    cout << "Done" << endl;
	return 0;
}