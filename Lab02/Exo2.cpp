/******************************************************************************
Design an Item class. Use a constructor to receive the item name, unit price, and quantity.
Then compute and output the total price. This problem practices creating an object with initial data using a constructor.
The input contains one line with name price quantity.
Sample Input 1: Pen 12 3
Output: Total: 36

*******************************************************************************/
#include <iostream>
#include <string>
using namespace std;

class Item {
    public:
    string Name;
    int price, quantity;
    
    Item (string name, int p, int q){
        Name = name;
        price = p;
        quantity = q;
    }
   int total(){
        return price * quantity;
    }
};

int main()
{
    string name;
    int p, q;
    cin >> name >> p >> q;
    Item item(name, p, q);
    std::cout<<"Total: " << item.total();

    return 0;
}