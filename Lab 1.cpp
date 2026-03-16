/******************************************************************************

Design a simpleBookclass concept to represent one book. Each book has three attributes: title, author, and number of pages.

In this problem, read the data of one book and output the book label in the required format.

The Online Judge only checks the output, but you are encouraged to practice the basic ideas ofclass and object in c++

The input contains one line with three fields:title author pages.

Output

Title: title
Author: author
Pages: pages
*******************************************************************************/
#include <iostream>
#include<string>
using namespace std;
class simpleBookclass {
    public:
    string title;
    string author;
    int NumPage;
};
int main()
{
  simpleBookclass BookClass;
  cin >> BookClass.title;
  cin >> BookClass.author;
  cin >> BookClass.NumPage;
  
  cout << "Title: " <<BookClass.title << endl;
  cout <<"Author: " <<BookClass.author << endl;
  cout << "Pages: " <<BookClass.NumPage << endl;
    return 0;
}