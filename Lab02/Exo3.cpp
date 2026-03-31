/******************************************************************************
Create three objects whose names are given in the input. Each object prints Construct name when constructed and Destruct name when destroyed.
After all three objects are created, print Ready. Observe the destruction order of objects in the same scope.
The input contains one line with three strings a b c without spaces.
Sample Input 1
A B C
Sample Output 1

Construct A
Construct B
Construct C
Ready
Destruct C
Destruct B
Destruct A
Source
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
	string a,b,c;
	cin >> a >> b >> c;
	Object o1(a);
	Object o2(b);
    Object o3(c);
    
    cout << "Ready" << endl;
	return 0;
}