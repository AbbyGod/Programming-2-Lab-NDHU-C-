/******************************************************************************
Solve this problem in an object-oriented way.
Design a base class Book with title and pages, and then design a derived class EBook with an extra data member fileSize.
After reading the data of one e-book, create an EBook object and output its title, pages, and file size.
The main goal of this problem is to use the basic inheritance syntax correctly.
The input contains one line with a string title, an integer pages, and an integer fileSize.
Output title pages fileSize separated by spaces.
Sample Input

CPPGuide 250 18
Sample Output 

CPPGuide 250 18
*******************************************************************************/
#include <iostream>
#include <string>
using namespace std;
class Book{
  public: 
  string title;
  int pages;
};
class Ebook:public Book{
    public:
    int filesize;
    void input(){
      cin >> title;
      cin >> pages;
      cin >> filesize;
  }
  
    void output(){
        cout << title << " " << pages << " " << filesize; 
    }
};

int main()
{
    Ebook book;
    book.input();
    book.output();

    return 0;
}



