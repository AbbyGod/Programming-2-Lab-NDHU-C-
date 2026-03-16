/******************************************************************************

Design a simpleWallclass concept to represent the size of one wall. A wall has two attributes: width and height.
Read the width and height, then output the area of the wall.
Although the judge only checks the output, you are encouraged to put the data in a class and let the object calculate the area.。
The input contains one line with two integerswidth height.

Output one line in the formatArea: X, whereXis the area of the wall.

*******************************************************************************/
#include <iostream>
#include<string>
using namespace std;

class SizeOfWall{
    public:
    int width;
    int height;
    int area(){
        return width * height;
    }
};

int main()
{
    
    SizeOfWall wall;
    std::cin >> wall.width;
    std::cin >> wall.height;
    
    std::cout<< "Area: " << wall.area();

    return 0;
}